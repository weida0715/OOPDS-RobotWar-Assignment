#include "BlueThunder.h"

void BlueThunder::action()
{
    int firePosX = neighbourhood[fireIndex][0];
    int firePosY = neighbourhood[fireIndex][1];
    fireIndex = (fireIndex + 1) % 8;
    fire(firePosX, firePosY);

    controller->updateBattlefield();
}
