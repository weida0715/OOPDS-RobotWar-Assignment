#include "Madbot.h"

void Madbot::action()
{
    int randIndex = rand() % 8;

    int firePosX = getRobotPositionX() + neighbourhood[randIndex][0];
    int firePosY = getRobotPositionY() + neighbourhood[randIndex][1];
    controller->updateBattlefield();
}
