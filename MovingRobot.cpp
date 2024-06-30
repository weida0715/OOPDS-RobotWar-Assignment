/**********|**********|**********|
Program: MovingRobot.cpp
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

#include "MovingRobot.h"

void MovingRobot::moveAux(int x, int y)
{
    int oldPosX = getRobotPositionX(),
        oldPosY = getRobotPositionY(),
        newPosX = x,
        newPosY = y;

    if (newPosX == -1 || newPosY == -1)
    {
        controller->displayMessage("No valid move");
        return;
    }

    controller->changeRobotPos(oldPosX, oldPosY, newPosX, newPosY);
    controller->displayMessage("Move to new location: (" + to_string(newPosX) + ", " + to_string(newPosY) + ")");
    controller->updateBattlefield();
}

void MovingRobot::move(int x, int y)
{
    moveAux(x, y);
}
