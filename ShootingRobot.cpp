#include "ShootingRobot.h"

void ShootingRobot::fireAux(int x, int y)
{
    stringstream fireMsg;

    int shootX = x + getRobotPositionX(),
        shootY = y + getRobotPositionY();
    fireMsg << "Fires at (" << shootX << ", " << shootY << ")";
    controller->displayMessage(fireMsg.str());

    if (controller->checkBoundary(shootX, shootY))
    {
        controller->displayMessage("Fire exceeds boundary\n");
        return;
    }

    fireMsg.str("");
    bool robotFound = false;
    robotFound = !controller->checkPosEmpty(shootX, shootY);
    if (robotFound)
    {
        Robot *detectedRobot = controller->searchRobot(shootX, shootY);
        fireMsg << "Enemy Robot <" << detectedRobot->getCurrType() << " "
                << detectedRobot->getRobotName() << "> at ("
                << shootX << ", " << shootY << ") is dead";
        controller->displayMessage(fireMsg.str());
        controller->killRobot(shootX, shootY);
        addKill();
        controller->displayKillCount(this);
    }
    else
    {
        fireMsg << "No enemy Robot found at (" << shootX
                << ", " << shootY << ")" << endl;
        controller->displayMessage(fireMsg.str());
    }
}

void ShootingRobot::fire(int x, int y)
{
    fireAux(x, y);
}
