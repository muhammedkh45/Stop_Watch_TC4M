/*
 * File:   Application.c
 * Author: Muhammed khalid
 * Created on June 6, 2024, 10:29 PM
 */

#include "stdint.h"
#include "MCAL/DIO.h"
#include "ECUAL/Seven Segmen.h"

uint8_t seg_common_cathode_values[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};



int main(void){

    GPIO_Init();
    while(1){
        char i =0;
        for(;i<5;++i){
            Se7en_Segment_Seconds_First_Digit(seg_common_cathode_values);
            Se7en_Segment_Seconds_Second_Digit(seg_common_cathode_values);
        }
        Se7en_Segment_Minutes_First_Digit(seg_common_cathode_values);
        if (Minutes_ext==0){
            Se7en_Segment_Minutes_Second_Digit(seg_common_cathode_values);
        }
        if (Minutes1_ext==0){
            Se7en_Segment_Hours_First_Digit(seg_common_cathode_values);
        }
        if(Hours_ext==0){
            Se7en_Segment_Hours_Second_Digit(seg_common_cathode_values);
        }

    }
}