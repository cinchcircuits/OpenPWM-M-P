/*
 * Copyright (c) 2015, Derek King
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

/* 
 * Getting compiler and tools (in Ubuntu)
 *  sudo apt-get update
 *  sudo apt-get install binutils-avr gcc-avr avrdude avr-libc
 */


/*
 * Fuses : want to run at 8Mhz off of internal oscillator
 * 
 * Extended Fuse Byte : 0xFF
 * unused [7:1]   
 * SELFPRGEN 0    : 1   : Self-prgromming enabled   : no
 *
 * High Fuse Byte : 11011111b = 0xDF
 * RSTDISBLE 7    : 1   : External reset disabled   : no
 * DWEN      6    : 1   : DebugWIRE active          : no
 * SPIEN     5    : 0   : Serial Program Enabled    : yes
 * WDTON     4    : 1   : Watchdog timer always on  : no
 * EESAVE    3    : 1   : EEPROM preserver on erase : no EEPROM not presevered
 * BODLEVEL [2:1] : 111 : Brownout Dectector level  : ?
 *
 * Low Fuse Byte : 11100010b = 0xE2
 * CKDIV8   7     : 1   : Clock Divided By 8        : don't divide by 8 (8Mhz internal osc)
 * CKOUT    6     : 1   : Clock output enabled      : no
 * SUT      [5:4] : 10  : Start-up time             : 14Clock cycles + 64ms
 * CLKSEL   [3:0] : 0010: Clock select              : calibrated internal osc
 *
 * http://www.engbedded.com/fusecalc/
 *  -U lfuse:w:0xe2:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m
 */


/* 
 * Notes
 *   avr-gcc -print-file-name=include 
 *   g/usr/lib/gcc/avr/4.5.3/include
 *   /usr/lib/avr/include/avr/iotn25.h
 */


/* Pin numbering defs */
enum {REV_PIN=0, FWD_PIN=1, PWM_PIN=2, LED_PIN=3, TEMP_PIN=4};



void setDuty(int16_t duty)
{
  if (duty>0xFF)
  {
    duty = 0xFF;
  }
  else if (duty < -0xFF)
  {
    duty = -0xFF;
  }

  if (duty < 0)
  {
    OCR0A = duty;
    OCR0B = 0xFF; // 0xFF high always
  }
  else 
  {    
    OCR0A = 0xFF; // 0xFF high always
    OCR0B = 0xFF-duty;
  }
}



ISR(TIMER1_OVF_vect)
{
  // Toggle LED
  PORTB |= (1<<LED_PIN);
  _delay_us(1);
  PORTB &= ~(1<<LED_PIN);  
}


int main(void)
{

  // Initialize Timer/Counter0 as two-output PWM
  enum { T0_COMv = 2 }; //non-inverting (for fast PWM)
  enum { T0_WGMv = 3 }; //fast PWM mode use 0xFF as TOP
  enum { T0_CSv = 1 };  //use internal clock with no prescalling
  TCCR0A = (T0_COMv<<COM0A0) | (T0_COMv<<COM0B0) | (T0_WGMv&3);
  TCCR0B = ((T0_WGMv>>2)<<WGM02) | T0_CSv;

  // Set initial duty values
  OCR0A = 0xFF;
  OCR0B = 0xFF;

  // Initialize Timer/Counter1 as free-running 0 to 0xFF
  // Pin change interrupt will read timer value on rising and falling edges 
  // and compare values to get pulse width. 
  // 
  // Have timer prescaled so that its period is longer than the longest
  // valid servo WPM pulse width that needs to be measured (2ms).
  //   2ms * 8Mhz / 256 = 62.5 --> set clock divider to 64
  enum { T1_CSv = 7 };  //use devide clock by 64
  TCCR1 = T1_CSv;  // all other bits are 0
  GTCCR = 0;
  PLLCSR = 0; // don't use external clock for timer1

  // Timer interrupt mask (for timer0 and timer1)
  // Use timer1 overflow interrupt to detect loss of servo PWM input signal
  TIMSK = (1<<TOIE1);  
  
  // PORTB data direction
  // 0 : REV  : output
  // 1 : FWD  : output
  // 2 : PWM  : input w/ pullup
  // 3 : LED  : output
  // 4 : TEMP : input
  DDRB = (1<<REV_PIN) | (1<<FWD_PIN) | (1<<LED_PIN);
  PORTB = (1<<LED_PIN) | (1<<PWM_PIN);

  // Enable interrupts
  sei();

  int16_t duty = 0;
  while (1)
  {
    _delay_ms(20);
    duty-=10;
    if (duty < -300)
    {
      duty = 0;
    }
    setDuty(duty);
  }

  return 0;
}
