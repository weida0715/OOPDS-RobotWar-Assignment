#include <iostream>
using namespace std;

#pragma once

#include "Robot.h"

class MovingRobot : virtual public Robot
{
public:
    virtual ~MovingRobot() {};

    void moveAux(int x, int y);
    virtual void move(int x, int y);
};
