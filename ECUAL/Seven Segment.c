/*
 * File:   Seven_segment.c
 * Author: Muhammed khalid
 * Created on June 6, 2024, 10:29 PM
 */

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "MCAL/Systick.h"
#include <stdbool.h>


bool End = false;
static uint8_t Minutes = 1 ;
static uint8_t Minutes_1 = 1 ;
static uint8_t Hours =1;
void Se7en_Segment_Seconds_First_Digit(uint8_t* index){
  uint8_t i =0;
	for(;i<10;++i){
  GPIO_PORTD_DATA_R =0x01;
  GPIO_PORTA_DATA_R = index[i];
	SysTick_Delay_1ms(100);
}
}
void Se7en_Segment_Seconds_Second_Digit(uint8_t* index){
	static uint8_t seconds =1;
  GPIO_PORTD_DATA_R =0x02;
  GPIO_PORTA_DATA_R = index[seconds];
	++seconds;
  if(seconds==6){seconds=0;}
}
void Se7en_Segment_Minutes_First_Digit(uint8_t* index){

	if (Minutes == 10 ){Minutes=0;}
  GPIO_PORTD_DATA_R =0x04;
  GPIO_PORTA_DATA_R = index[Minutes];
	Minutes++;

}
void Se7en_Segment_Minutes_Second_Digit(uint8_t* index){

	if(Minutes_1==6){Minutes_1=0;}
  GPIO_PORTD_DATA_R =0x08;
  GPIO_PORTA_DATA_R = index[Minutes_1];
	++Minutes_1;
  
}

	void Se7en_Segment_Hours_First_Digit(uint8_t* index){
  if(End==false){

	if (Hours == 10 ){Hours=0;}
  GPIO_PORTD_DATA_R =0x10;
  GPIO_PORTA_DATA_R = index[Hours];
	++Hours;
	}
	else if (End==true){
	static uint8_t Hours =1;
	if (Hours == 5 ){Hours=0;}
  GPIO_PORTD_DATA_R =0x10;
  GPIO_PORTA_DATA_R = index[Hours];
	++Hours;
	}
}
void Se7en_Segment_Hours_Second_Digit( uint8_t* index){
  static uint8_t Hours_1 = 1;
  if(Hours_1==3){
		Hours_1=0 ;
		End =true;
	}
  GPIO_PORTD_DATA_R =0x20;
  GPIO_PORTA_DATA_R = index[Hours_1];

}
