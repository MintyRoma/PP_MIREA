#pragma once
#include <iostream>
#include <string>

#define star 'Æ'
#define empty '.'
#define stripe '#'
#define height 13
#define width (int) height*1.9*2

#define RED "\033[31m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define BLUEBACK "\033[44m"
#define RESETBACK "\033[40m"


void DrawStars(int row);
void DrawPattern(int row);