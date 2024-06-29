#include <iostream>
using namespace std;

#pragma once

#include "SimulationController.h"
#include "Logger.h"

class SimulationController;
class TurnList;
class Robot;
class Logger;

class SimulationView
{
private:
    SimulationController *controller;
    Logger *logger;

public:
    void setController(SimulationController *c);
    void setLogger(Logger *l);

    void print(string message);
    void log(string message);
    void printAndLog(string message);

    void displayFileData();
    void displayRobotInfo(Robot *robot);
    void displayBattlefield(Robot ***robotGrid);
    void displayTurn();
    void displayKillCount(Robot *robot);
};
