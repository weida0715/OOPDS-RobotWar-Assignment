#include <iostream>
using namespace std;

#pragma once

#include "Robot.h"

class ShootingRobot : virtual public Robot
{
public:
    virtual ~ShootingRobot() {};

    void fireAux(int x, int y);
    virtual void fire(int x, int y);
};
