/**********|**********|**********|
Program: Robot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Lecture Section: TC2L
Tutorial Section: TT8L

Name: Ng Wei Da
ID: 1211107034
Email: 1211107034@student.mmu.edu.my
Phone: 016-529 7743

Name: CHAN ZHENG UEE
ID: 1231302741
Email: 1231302741@student.mmu.edu.my
Phone: 010-650 8285

Name: TEO HOCK SENG
ID: 1231302732
Email: 1231302732@student.mmu.edu.my
Phone: 012-812 6136

Name: Sia Jing Liang
ID: 1211106208
Email: 1211106208@student.mmu.edu.my
Phone: 016-271 6656
**********|**********|**********/

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
