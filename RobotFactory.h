#include <iostream>
using namespace std;

#pragma once

#include "Robot.h"

class Robot;

class RobotFactory
{
public:
    Robot *getRobot(string type, string name, int x, int y);
};
