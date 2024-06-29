#include <iostream>
using namespace std;

#pragma once

#include "SeeingRobot.h"
#include "MovingRobot.h"
#include "SteppingRobot.h"

class Terminator : public SeeingRobot,
                   public MovingRobot,
                   public SteppingRobot
{
public:
    Terminator() = default;
    Terminator(string name, int x, int y, string initType = "", string robotChar = "")
        : Robot(name, "Terminator", x, y, initType, robotChar){};

    ~Terminator() {}

    void look(int x, int y) override;
    void action() override;
};
