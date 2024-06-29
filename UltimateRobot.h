#include <iostream>
using namespace std;

#pragma once

#include "SeeingRobot.h"
#include "MovingRobot.h"
#include "SteppingRobot.h"
#include "ShootingRobot.h"

class UltimateRobot : public SeeingRobot,
                      public MovingRobot,
                      public SteppingRobot,
                      public ShootingRobot
{
public:
    UltimateRobot(string name, int x, int y, string initType = "", string robotChar = "")
        : Robot(name, "UltimateRobot", x, y, initType, robotChar){};

    ~UltimateRobot() override {}

    void look(int x, int y) override;
    void action() override;
};
