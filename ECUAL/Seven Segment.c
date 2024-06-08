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
static uint8_t seconds = 1;
static uint8_t Minutes = 1 ;
static uint8_t Minutes_1 = 1 ;
static uint8_t Hours =1;
uint8_t Data;
uint8_t Minutes_ext;
uint8_t Minutes1_ext;
uint8_t Hours_ext;

void PrintData(uint8_t data) {
    if(data & 0x01 ){GPIO_PORTB_DATA_R |= 0x01;}
    else if (!(data & 0x01)) {GPIO_PORTB_DATA_R &=~0x01;}
    if(data & 0x02 ){GPIO_PORTB_DATA_R |= 0x02;}
    else if (!(data & 0x02)) {GPIO_PORTB_DATA_R &=~0x02;}
    if(data & 0x04 ){GPIO_PORTE_DATA_R |= 0x10;}
    else if (!(data & 0x04)) {GPIO_PORTE_DATA_R &=~0x10;}
    if(data & 0x08 ){GPIO_PORTE_DATA_R |= 0x20;}
    else if (!(data & 0x08)) {GPIO_PORTE_DATA_R &=~0x20;}
    if(data & 0x10 ){GPIO_PORTB_DATA_R |= 0x10;}
    else if (!(data & 0x10)) {GPIO_PORTB_DATA_R &=~0x10;}
    if(data & 0x20 ){GPIO_PORTA_DATA_R |= 0x20;}
    else if (!(data & 0x20)) {GPIO_PORTA_DATA_R &=~0x20;}
    if(data & 0x40 ){GPIO_PORTA_DATA_R |= 0x40;}
    else if (!(data & 0x40)) {GPIO_PORTA_DATA_R &=~0x40;}
}

void Se7en_Segment_Seconds_First_Digit(const uint8_t* index){
    uint8_t i =0;
    GPIO_PORTD_DATA_R = 0x0E;
    for(;i<10;++i){
        Data = index[i];
        PrintData(Data);
        SysTick_Delay_1ms(100);
    }
}
void Se7en_Segment_Seconds_Second_Digit(const uint8_t* index){
    GPIO_PORTD_DATA_R = 0x0D;
    Data = index[seconds];
    PrintData(Data);
    SysTick_Delay_1ms(50);
    ++seconds;
    if(seconds==6){seconds=1;}
}
void Se7en_Segment_Minutes_First_Digit(const uint8_t* index){
    GPIO_PORTD_DATA_R = 0x0B;
    if (Minutes == 10 ){Minutes=0;}
    Data = index[Minutes];
    PrintData(Data);
    SysTick_Delay_1ms(50);
    Minutes++;
    Minutes_ext = Minutes;
}
void Se7en_Segment_Minutes_Second_Digit(const uint8_t* index){
    GPIO_PORTD_DATA_R = 0x07;
    if(Minutes_1==6){Minutes_1=1;}
    Data = index[Minutes_1];
    PrintData(Data);
    SysTick_Delay_1ms(50);
    ++Minutes_1;
    Minutes1_ext = Minutes_1;
}

void Se7en_Segment_Hours_First_Digit(const uint8_t* index){
    GPIO_PORTE_DATA_R = 0x04;
    if(End==false){

        if (Hours == 10 ){
            Hours=0;
        }
        Data= index[Hours];
        PrintData(Data);
        SysTick_Delay_1ms(50);
        ++Hours;
        Hours_ext = Hours;

    }
    else if (End==true) {
        static uint8_t Hours_0 = 1;
        if (Hours_0 == 5) { Hours_0 = 0; }
        Data = index[Hours_0];
        PrintData(Data);
        SysTick_Delay_1ms(50);
        ++Hours_0;
        Hours_ext = Hours_0;
    }
}
void Se7en_Segment_Hours_Second_Digit(const uint8_t* index){
    GPIO_PORTE_DATA_R = 0x02;
    static uint8_t Hours_1 = 1;
    if(Hours_1==3){
        Hours_1=0 ;
        End =true;
    }
    Data = index[Hours_1];
    PrintData(Data);
    SysTick_Delay_1ms(50);
}




