/**********|**********|**********|
Program: ShootingRobot.cpp
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
