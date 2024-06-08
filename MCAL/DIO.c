/*
 * File:   DIO.c
 * Author: Muhammed khalid
 * Created on June 6, 2024, 10:29 PM
 */

#include "stdint.h"
#include "tm4c123gh6pm.h"
void GPIO_Init(void){
	  // PORTA initialization
        SYSCTL_RCGCGPIO_R |= 0x01;
        while((SYSCTL_PRGPIO_R & 0x01) == 0);
        GPIO_PORTA_AFSEL_R &= ~0x60;
        GPIO_PORTA_AMSEL_R &=~0x60;
        GPIO_PORTA_PCTL_R &=~ 0x0FF00000;
        GPIO_PORTA_DEN_R |= 0x60;
        GPIO_PORTA_DIR_R |= 0x60;

        // PORTB initialization
        SYSCTL_RCGCGPIO_R |= 0x02;
        while((SYSCTL_PRGPIO_R & 0x02) == 0);
        GPIO_PORTB_AFSEL_R &= ~0x13;
        GPIO_PORTB_AMSEL_R &=~0x13;
        GPIO_PORTB_PCTL_R&=~0x000F00FF;
        GPIO_PORTB_DEN_R |= 0x13;
        GPIO_PORTB_DIR_R |= 0x13;

        //PORTD initialization
        SYSCTL_RCGCGPIO_R |= 0x08;
        while((SYSCTL_PRGPIO_R & 0x08) == 0);
        GPIO_PORTD_CR_R  =0x3F;
        GPIO_PORTD_AFSEL_R &= ~0x3F;
        GPIO_PORTD_AMSEL_R &=~0x3F;
        GPIO_PORTD_PCTL_R&=~0x00FFFFFF;
        GPIO_PORTD_DEN_R |= 0x3F;
        GPIO_PORTD_DIR_R |= 0x3F;

        // PORTE initialization
        SYSCTL_RCGCGPIO_R |= 0x10;
        while((SYSCTL_PRGPIO_R & 0x10) == 0);
        GPIO_PORTE_AFSEL_R &= ~0x30;
        GPIO_PORTE_AMSEL_R &=~0x30;
        GPIO_PORTE_PCTL_R&=~0x00FF0000;
        GPIO_PORTE_DEN_R |= 0x30;
        GPIO_PORTE_DIR_R |= 0x30;

		
}

    