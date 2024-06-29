#include "SteppingRobot.h"

void SteppingRobot::stepAux(int x, int y)
{
    stringstream stepMsg;
    stepMsg << "Stepping at (" << x << ", " << y << ")" << endl;

    Robot *detectedRobot = controller->searchRobot(x, y);
    stepMsg << "Enemy Robot <" << detectedRobot->getCurrType() << " "
            << detectedRobot->getRobotName() << "> at ("
            << x << ", " << y << ") is killed by stepping" << endl;
    controller->killRobot(x, y);
    addKill();
    controller->displayKillCount(this);
    controller->displayMessage(stepMsg.str());
}

void SteppingRobot::step(int x, int y)
{
    stepAux(x, y);
}
