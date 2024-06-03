/*
 * File:   Application.c
 * Author: Muhammed khalid
 * Created on June 6, 2024, 10:29 PM
 */

#include "stdint.h"
#include "MCAL/Systick.h"
#include "MCAL/DIO.h"
#include "ECUAL/Seven Segmen.h"

uint8_t seg_common_cathod_values[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};



int main(void){
	char i =0;
	GPIO_Init();
	while(1){
		for(;i<5;++i){
			Se7en_Segment_Seconds_First_Digit(seg_common_cathod_values);
			Se7en_Segment_Seconds_Second_Digit(seg_common_cathod_values);
		}
			Se7en_Segment_Minutes_First_Digit(seg_common_cathod_values);
			if (Minutes==0){
			Se7en_Segment_Minutes_Second_Digit(seg_common_cathod_values);
			}
			if (Minutes_1==0){
			Se7en_Segment_Hours_First_Digit(seg_common_cathod_values);
			}
			if(Hours==0){
				Se7en_Segment_Hours_Second_Digit(seg_common_cathod_values);
			}
	}
}