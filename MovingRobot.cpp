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
