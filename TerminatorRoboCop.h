#include <iostream>
using namespace std;

#pragma once

#include "SeeingRobot.h"
#include "MovingRobot.h"
#include "SteppingRobot.h"
#include "ShootingRobot.h"

class TerminatorRoboCop : public SeeingRobot,
                          public MovingRobot,
                          public SteppingRobot,
                          public ShootingRobot
{
public:
    TerminatorRoboCop() = default;
    TerminatorRoboCop(string name, int x, int y, string initType = "", string robotChar = "")
        : Robot(name, "TerminatorRoboCop", x, y, initType, robotChar) {};

    ~TerminatorRoboCop() {}

    void look(int x, int y) override;
    void action() override;
};
