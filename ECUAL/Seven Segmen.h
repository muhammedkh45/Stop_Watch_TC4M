/*
 * File:   Seven_segment.h
 * Author: Muhammed khalid
 * Created on June 6, 2024, 10:29 PM
 */

#ifndef _SEVEN_SEGMENT_H_
#define _SEVEN_SEGMENT_H_

#include"stdint.h"
extern uint8_t Minutes_ext ;
extern uint8_t Minutes1_ext;
extern uint8_t Hours_ext;
void Se7en_Segment_Seconds_First_Digit(const uint8_t* index);
void Se7en_Segment_Seconds_Second_Digit(const uint8_t* index);
void Se7en_Segment_Minutes_First_Digit(const uint8_t* index);
void Se7en_Segment_Minutes_Second_Digit(const uint8_t* index);
void Se7en_Segment_Hours_First_Digit(const uint8_t* index);
void Se7en_Segment_Hours_Second_Digit(const uint8_t* index);
void PrintData(uint8_t data);
#endif /*_SEVEN_SEGMENT_H_*/