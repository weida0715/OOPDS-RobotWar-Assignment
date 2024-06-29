#include <iostream>
using namespace std;

#pragma once

#include "ShootingRobot.h"

class Madbot : public ShootingRobot
{
public:
    Madbot() = default;
    Madbot(string name, int x, int y, string initType = "", string robotChar = "")
        : Robot(name, "Madbot", x, y, initType, robotChar) {};

    ~Madbot() {}

    void action() override;
};
