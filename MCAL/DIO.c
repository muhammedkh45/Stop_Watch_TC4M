/*
 * File:   DIO.c
 * Author: Muhammed khalid
 * Created on June 6, 2024, 10:29 PM
 */

#include "stdint.h"
#include "tm4c123gh6pm.h"
void GPIO_Init(void){
	  // PORTA initailization 
    SYSCTL_RCGCGPIO_R |= 0x01;            // activate clock for Port A
    while((SYSCTL_PRGPIO_R & 0x01) == 0);  // allow time for clock to start
		GPIO_PORTA_CR_R  =0xFF;
    GPIO_PORTA_AFSEL_R &= ~0xFF;          // disable alt funct on PA7-0
		GPIO_PORTA_AMSEL_R &=~0xFF;
		GPIO_PORTA_PCTL_R&=~0xFFFFFFFF;
		GPIO_PORTA_DEN_R |= 0xFF;             // enable digital I/O on PA7-0
		GPIO_PORTA_DIR_R |= 0xFF;            // make PA7-0 output
	  
		//PORTD initialization
	  SYSCTL_RCGCGPIO_R |= 0x08;          // activate clock for Port D
    while((SYSCTL_PRGPIO_R & 0x08) == 0); // allow time for clock to start
   	GPIO_PORTD_CR_R  =0x3F;
    GPIO_PORTD_AFSEL_R &= ~0x3F;        // disable alt funct on PD5-0
	  GPIO_PORTD_AMSEL_R &=~0x3F;
	  GPIO_PORTD_PCTL_R&=~0x00FFFFFF;
    GPIO_PORTD_DEN_R |= 0x3F;
	  GPIO_PORTD_DIR_R |= 0x3F;           // make PD5-0 output
		
		
}

    