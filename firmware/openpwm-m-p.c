#include <avr/io.h>
#define F_CPU 8000000UL

#include <stdint.h>
#include <util/delay.h>

// sudo apt-get update
// sudo apt-get install binutils-avr gcc-avr avrdude avr-libc

// avr-gcc -print-file-name=include
// g/usr/lib/gcc/avr/4.5.3/include
// /usr/lib/avr/include/avr/iotn25.h


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
