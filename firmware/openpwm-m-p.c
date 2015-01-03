#include <avr/io.h>
#define F_CPU 8000000UL

#include <stdint.h>
#include <util/delay.h>

// sudo apt-get update
// sudo apt-get install binutils-avr gcc-avr avrdude avr-libc

// avr-gcc -print-file-name=include
// g/usr/lib/gcc/avr/4.5.3/include
// /usr/lib/avr/include/avr/iotn25.h

//-U lfuse:w:0xe2:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m
// CKSEL[3:0] = 2 : Calibrated internal osc
// SUT[1:0] = 2   : 14CK + 64ms


// Extended Fuse Byte : 0xFF
// unused [7:1]   
// SELFPRGEN 0    : 1   : Self-prgromming enabled   : no
//
// High Fuse Byte : 11011111b = 0xDF
// RSTDISBLE 7    : 1   : External reset disabled   : no
// DWEN      6    : 1   : DebugWIRE active          : no
// SPIEN     5    : 0   : Serial Program Enabled    : yes
// WDTON     4    : 1   : Watchdog timer always on  : no
// EESAVE    3    : 1   : EEPROM preserver on erase : no EEPROM not presevered
// BODLEVEL [2:1] : 111 : Brownout Dectector level  : ?
//
// Low Fuse Byte : 11100010b = 0xE2
// CKDIV8   7     : 1   : Clock Divided By 8        : don't divide by 8 (8Mhz internal osc)
// CKOUT    6     : 1   : Clock output enabled      : no
// SUT      [5:4] : 10  : Start-up time             : 14Clock cycles + 64ms
// CLKSEL   [3:0] : 0010: Clock select              : calibrated internal osc
//
// http://www.engbedded.com/fusecalc/
// -U lfuse:w:0xe2:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m


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


int main(void)
{

  // Initialize OC1 as two-output PWM
  enum { COMv = 2 }; //non-inverting (for fast PWM)
  enum { WGMv = 3 }; //fast PWM mode use 0xFF as TOP
  enum { CSv = 1 };  //use internal clock with no prescalling
  TCCR0A = (COMv<<COM0A0) | (COMv<<COM0B0) | (WGMv&3);
  TCCR0B = ((WGMv>>2)<<WGM02) | CSv;
  OCR0A = 0xC0;
  OCR0B = 0x80;

  // PORTB data direction
  // 0 : REV  : output
  // 1 : FWD  : output
  // 2 : PWM  : input w/ pullup
  // 3 : LED  : output
  // 4 : TEMP : input
  enum {REV_PIN=0, FWD_PIN=1, PWM_PIN=2, LED_PIN=3, TEMP_PIN=4};
  DDRB = (1<<REV_PIN) | (1<<FWD_PIN) | (1<<LED_PIN);
  PORTB = (1<<LED_PIN) | (1<<PWM_PIN);
  
  int16_t duty = 0;
  while (1)
  {
    PORTB |=  (1<<LED_PIN);
    _delay_ms(10);
    PORTB &=~ (1<<LED_PIN);
    _delay_ms(10);
    duty-=10;
    if (duty < -300)
    {
      duty = 0;
    }
    setDuty(duty);
  }

  return 0;
}
