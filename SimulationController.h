/**********|**********|**********|
Program: SimulationController.h
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
#include <fstream>
#include <ctime>
using namespace std;

#pragma once

#include "SimulationModel.h"
#include "SimulationView.h"
#include "Logger.h"
// #include "Robot.h"
#include "TurnList.h"
#include "DeathQueue.h"
#include "RobotFactory.h"

class SimulationModel;
class SimulationView;
class RobotFactory;

class SimulationController
{
private:
    SimulationModel *model;
    SimulationView *view;
    Logger logger;
    RobotFactory *robotFactory;
    Robot ***robotGrid;
    TurnList turnList;
    DeathQueue deathQueue;
    int stepCount = 0;

public:
    SimulationController(SimulationModel *m, SimulationView *v);
    ~SimulationController();

    int getM();
    int getN();
    int getSteps();
    int getNumRobots();
    string *getRobotNames();
    string *getRobotTypes();
    string *getRobotXs();
    string *getRobotYs();
    int getStepCount();

    // Logging logic
    void logToFile(string filename);
    void displayMessage(string message);

    // Robot Logic
    void generateRobots();
    bool checkBoundary(int x, int y);
    bool checkPosEmpty(int x, int y);
    Robot *searchRobot(int x, int y);
    void killRobot(int x, int y);
    void displayKillCount(Robot *robot);
    void upgradeRobot(Robot **robot);
    void downgradeRobot(Robot **robot);

    // Battlefield Logic
    void updateBattlefield();
    void changeRobotPos(int oldX, int oldY, int newX, int newY);

    void initSimulator(string filename);
    void runSimulator(string filename);
};
