#include <iostream>
using namespace std;

#pragma once

#include "Robot.h"

class SteppingRobot : virtual public Robot
{
public:
    virtual ~SteppingRobot() {};

    void stepAux(int x, int y);
    virtual void step(int x, int y);
};
