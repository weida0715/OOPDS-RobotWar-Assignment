/**********|**********|**********|
Program: UltimateRobot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Lecture Section: TC2L
Tutorial Section: TT8L

Name: Ng Wei Da
ID: 1211107034
Email: 1211107034@student.mmu.edu.my
Phone: 016-529 7743

Name: CHAN ZHENG UEE
ID: 1231302741
Email: 1231302741@student.mmu.edu.my
Phone: 010-650 8285

Name: TEO HOCK SENG
ID: 1231302732
Email: 1231302732@student.mmu.edu.my
Phone: 012-812 6136

Name: Sia Jing Liang
ID: 1211106208
Email: 1211106208@student.mmu.edu.my
Phone: 016-271 6656
**********|**********|**********/

#include "UltimateRobot.h"

void UltimateRobot::look(int x, int y)
{
    return lookAux(x, y, true);
}

void UltimateRobot::action()
{
    look(0, 0);
    if (detectedRobotCount > 0)
        step(decidedX, decidedY);
    else
        move(decidedX, decidedY);

    int randX = -1, randY = -1, fireCount = 0;
    do
    {
        randX = rand() % controller->getM();
        randY = rand() % controller->getN();
        if (randX != 0 || randY != 0)
        {
            fire(randX, randY);
            fireCount++;
        }
    } while (fireCount < 3);

    controller->updateBattlefield();
}
