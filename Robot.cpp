#include "Robot.h"

int Robot::robotCount = 0;

Robot::Robot(string name, string type, int x, int y,
             string initType, string robotChar)
    : robotName(name), currType(type),
      lives(3), killCount(0), robotId(++robotCount)
{
    this->robotPositionX = x;
    this->robotPositionY = y;
    this->robotChar =
        (robotChar == "")
            ? string(1, type[0]) + string(1, name[0]) + to_string(robotId % 10)
            : robotChar;
    this->initType =
        (initType == "")
            ? type
            : initType;
}

Robot::~Robot() { robotCount--; };

int Robot::getRobotId() { return robotId; }
int Robot::getRobotPositionX() { return robotPositionX; }
int Robot::getRobotPositionY() { return robotPositionY; }
int Robot::getLives() { return lives; }
int Robot::getKillCount() { return killCount; }
string Robot::getRobotChar() { return robotChar; }
string Robot::getRobotName() { return robotName; }
string Robot::getInitType() { return initType; }
string Robot::getCurrType() { return currType; }

void Robot::setController(SimulationController *c) { controller = c; }
void Robot::setRobotPositionX(int x) { robotPositionX = x; }
void Robot::setRobotPositionY(int y) { robotPositionY = y; }
void Robot::setRobotId(int id) { robotId = id; };
void Robot::setRobotChar(string c) { robotChar = c; }
void Robot::setRobotName(string n) { robotName = n; }
void Robot::setInitType(string t) { initType = t; }
void Robot::setCurrType(string t) { currType = t; }

void Robot::lostLife() { lives--; }
void Robot::addKill() { killCount++; }
void Robot::resetKill() { killCount = 0; }

int Robot::getRobotCount() { return robotCount; }
