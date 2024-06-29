#include "RoboTank.h"

void RoboTank::action()
{
    int randX = -1, randY = -1;
    do
    {
        randX = rand() % controller->getN();
        randY = rand() % controller->getM();
    } while (randX == 0 && randY == 0);

    fire(randX, randY);

    controller->updateBattlefield();
}
