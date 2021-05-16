#include "student.h"

#define DEFAUT_SPEED 80
Student::Student()
{
    chooseType = 0;
    speed = DEFAUT_SPEED; // m/min
    currentX = 0;
    currentY = 0;
}
