#include "RoboCop.h"
void RoboCop::action()
{
    look(0, 0);
    move(decidedX, decidedY);

    int fireX = -1, fireY = -1,
        maxRange = 10, rangeLeft = maxRange,
        fireCount = 0;
    do
    {
        fireX = rand() % 21 - maxRange;

        int rangeLeft = maxRange - abs(fireX);
        fireY = rand() % (2 * rangeLeft + 1) - rangeLeft;

        if (fireX != 0 && fireY != 0 && !controller->checkBoundary(fireX + getRobotPositionX(), fireY + getRobotPositionY()))
        {
            fire(fireX, fireY);
            fireCount++;
        }
    } while (fireCount < 3);

    controller->updateBattlefield();
}
