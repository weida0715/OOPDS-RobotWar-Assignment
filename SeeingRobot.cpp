/**********|**********|**********|
Program: SeeingRobot.cpp
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

#include "SeeingRobot.h"
#include <iostream>
#include <sstream>

void SeeingRobot::lookAux(int x, int y, bool preferEnemy)
{
    detectedRobotCount = 0;
    emptyRobotCount = 0;
    decidedX = -1;
    decidedY = -1;

    stringstream lookMsg;
    int lookPosX = getRobotPositionX() + x,
        lookPosY = getRobotPositionY() + y;

    controller->displayMessage("Looking at (" + to_string(x) + ", " + to_string(y) + ")");

    for (int i = 0; i < 8; i++)
    {
        emptyRobotPos[i] = -1;
        detectedRobotPos[i] = -1;
    }

    for (int i = 0; i < 8; i++)
    {
        int scanX = lookPosX + neighbourhood[i][0];
        int scanY = lookPosY + neighbourhood[i][1];

        if (!controller->checkBoundary(scanX, scanY))
        {
            Robot *enemyRobot = controller->searchRobot(scanX, scanY);

            if (enemyRobot != nullptr)
            {
                detectedRobotPos[detectedRobotCount] = i;
                detectedRobotCount++;
                lookMsg << "Enemy Robot <" << enemyRobot->getCurrType() << " "
                        << enemyRobot->getRobotName() << "> spotted at ("
                        << scanX << ", " << scanY << ")" << endl;
            }
            else
            {
                emptyRobotPos[emptyRobotCount] = i;
                emptyRobotCount++;
                lookMsg << "No enemy Robot found at (" << scanX << ", " << scanY << ")" << endl;
            }
        }
        else
            lookMsg << "(" << scanX << ", " << scanY << ") exceeds the boundary" << endl;
    }
    controller->displayMessage(lookMsg.str());

    int randPos = -1;
    if (preferEnemy && detectedRobotCount > 0)
        randPos = detectedRobotPos[rand() % detectedRobotCount];
    else if (emptyRobotCount > 0)
        randPos = emptyRobotPos[rand() % emptyRobotCount];

    if (randPos != -1)
    {
        decidedX = neighbourhood[randPos][0] + getRobotPositionX();
        decidedY = neighbourhood[randPos][1] + getRobotPositionY();
    }
}

void SeeingRobot::look(int x, int y)
{
    lookAux(x, y, false);
}
