#include <iostream>
using namespace std;

#pragma once

#include "Robot.h"

class SeeingRobot : virtual public Robot
{
protected:
    int detectedRobotCount, emptyRobotCount;
    int detectedRobotPos[8], emptyRobotPos[8];
    int decidedX, decidedY;

public:
    virtual ~SeeingRobot() {}

    void lookAux(int x, int y, bool preferEnemy);
    virtual void look(int x, int y);
};
