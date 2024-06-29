#include <iostream>
using namespace std;

#pragma once

#include "SeeingRobot.h"
#include "MovingRobot.h"
#include "ShootingRobot.h"

class RoboCop : public SeeingRobot,
                public MovingRobot,
                public ShootingRobot
{
public:
    RoboCop() = default;
    RoboCop(string name, int x, int y, string initType = "", string robotChar = "")
        : Robot(name, "RoboCop", x, y, initType, robotChar) {}

    ~RoboCop() {}

    void action() override;
};
