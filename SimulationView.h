/**********|**********|**********|
Program: SimulationView.h
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
