#include <iostream>
using namespace std;

#pragma once

#include "ShootingRobot.h"

class RoboTank : public ShootingRobot
{
public:
    RoboTank() = default;
    RoboTank(string name, int x, int y, string initType = "", string robotChar = "")
        : Robot(name, "RoboTank", x, y, initType, robotChar){};

    ~RoboTank() {}

    void action() override;
};
