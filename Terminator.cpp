#include "Terminator.h"

void Terminator::look(int x, int y)
{
    return lookAux(x, y, true);
}

void Terminator::action()
{
    look(0, 0);
    if (detectedRobotCount > 0)
        step(decidedX, decidedY);
    else
        move(decidedX, decidedY);

    controller->updateBattlefield();
}
