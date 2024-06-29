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
        if (randX != 0 && randY != 0)
            fire(randX, randY);
            fireCount++;
    } while (fireCount < 3);

    controller->updateBattlefield();
}
