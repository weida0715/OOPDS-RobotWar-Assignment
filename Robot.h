#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#pragma once

#include "SimulationController.h"

class SimulationController;

class Robot
{
private:
    static int robotCount;
    int robotId;
    int robotPositionX, robotPositionY;
    int lives;
    int killCount;
    string robotChar, robotName;
    string initType, currType;

protected:
    SimulationController *controller;
    int neighbourhood[8][2] = {
        {0, -1}, // Up 0
        {1, -1}, // Up-Right 1
        {1, 0},  // Right 2
        {1, 1},  // Down-Right 3
        {0, 1},  // Down 4
        {-1, 1}, // Down-Left 5
        {-1, 0}, // Left 6
        {-1, -1} // Up-Left 7
    };

public:
    Robot() = default;
    Robot(string name, string type, int x, int y,
          string initType = "", string robotChar = "");
    virtual ~Robot();

    int getRobotId();
    int getRobotPositionX();
    int getRobotPositionY();
    int getLives();
    int getKillCount();
    string getRobotChar();
    string getRobotName();
    string getInitType();
    string getCurrType();

    void setController(SimulationController *c);
    void setRobotPositionX(int x);
    void setRobotPositionY(int y);
    void setRobotId(int id);
    void setRobotChar(string c);
    void setRobotName(string n);
    void setInitType(string t);
    void setCurrType(string t);

    void lostLife();
    void addKill();
    void resetKill();

    static int getRobotCount();

    virtual void action() = 0;
};
