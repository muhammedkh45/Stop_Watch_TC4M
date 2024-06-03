cmake_minimum_required(VERSION 3.28)
project(7_segment C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(7_segment
        MCAL/DIO.c
        MCAL/DIO.h
        Application.c
        "ECUAL/Seven Segmen.h"
        "ECUAL/Seven Segment.c"
        MCAL/SysTick.c
        MCAL/Systick.h
        tm4c123gh6pm.h)
