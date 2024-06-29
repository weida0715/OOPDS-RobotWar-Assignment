#include <iostream>
using namespace std;

#pragma once

#include "ShootingRobot.h"

class BlueThunder : public ShootingRobot
{
private:
    int fireIndex;

public:
    BlueThunder() = default;
    BlueThunder(string name, int x, int y, string initType = "", string robotChar = "")
        : Robot(name, "BlueThunder", x, y, initType, robotChar), fireIndex(0) {};

    ~BlueThunder() {}

    void action() override;
};
