/**********|**********|**********|
Program: SimulationController.cpp
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

#include "SimulationController.h"

SimulationController::SimulationController(SimulationModel *m, SimulationView *v)
    : model(m), view(v)
{
    srand(time(0));
    view->setController(this);
    view->setLogger(&logger);
}

SimulationController::~SimulationController()
{
    int M = model->getM();
    int N = model->getN();
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete robotGrid[i][j];
        }
        delete[] robotGrid[i];
    }
    delete[] robotGrid;

    while (!deathQueue.empty())
    {
        Robot *robot = deathQueue.front();
        deathQueue.dequeue();
        delete robot;
    }
}

int SimulationController::getM() { return model->getM(); }
int SimulationController::getN() { return model->getN(); }
int SimulationController::getSteps() { return model->getSteps(); }
int SimulationController::getNumRobots() { return model->getNumRobots(); }
string *SimulationController::getRobotTypes() { return model->getRobotTypes(); }
string *SimulationController::getRobotNames() { return model->getRobotNames(); }
string *SimulationController::getRobotXs() { return model->getRobotXs(); }
string *SimulationController::getRobotYs() { return model->getRobotYs(); }
int SimulationController::getStepCount() { return stepCount; }

void SimulationController::logToFile(string filename)
{
    logger.logToFile(filename);
}

void SimulationController::displayMessage(string message)
{
    view->printAndLog(message);
}

void SimulationController::generateRobots()
{
    int numRobots = model->getNumRobots();
    string *robotNames = model->getRobotNames(),
           *robotTypes = model->getRobotTypes(),
           *robotXs = model->getRobotXs(),
           *robotYs = model->getRobotYs();

    int tempX, tempY;
    for (int i = 0; i < numRobots; i++)
    {
        if (robotXs[i] != "random" && robotYs[i] != "random")
        {
            tempX = stoi(robotXs[i]);
            tempY = stoi(robotYs[i]);
        }
        else
        {
            do
            {
                if (robotXs[i] == "random")
                    tempX = rand() % model->getN();
                else
                    tempX = stoi(robotXs[i]);

                if (robotYs[i] == "random")
                    tempY = rand() % model->getM();
                else
                    tempY = stoi(robotYs[i]);
            } while (robotGrid[tempY][tempX] != nullptr);
        }

        Robot *newRobot = robotFactory->getRobot(robotTypes[i], robotNames[i], tempX, tempY);
        newRobot->setController(this);
        robotGrid[tempY][tempX] = newRobot;
        turnList.push_back(newRobot);
    }
}

bool SimulationController::checkBoundary(int x, int y)
{
    return (x < 0 || x >= model->getN() || y < 0 || y >= model->getM());
}

bool SimulationController::checkPosEmpty(int x, int y)
{
    return (robotGrid[y][x] == nullptr);
}

Robot *SimulationController::searchRobot(int x, int y)
{
    return robotGrid[y][x];
}

void SimulationController::updateBattlefield()
{
    view->displayBattlefield(robotGrid);
}

void SimulationController::changeRobotPos(int oldX, int oldY, int newX, int newY)
{
    Robot *robot = robotGrid[oldY][oldX];
    robotGrid[newY][newX] = robot;
    robotGrid[oldY][oldX] = nullptr;
    robot->setRobotPositionX(newX);
    robot->setRobotPositionY(newY);
}

void SimulationController::killRobot(int x, int y)
{
    Robot *killedRobot = robotGrid[y][x];

    killedRobot->lostLife();
    turnList.remove(killedRobot);

    stringstream killMsg;
    killMsg << "<" << killedRobot->getCurrType() << " "
            << killedRobot->getRobotName() << "> has "
            << killedRobot->getLives() << " lives left" << endl;

    if (killedRobot->getLives() > 0)
    {
        downgradeRobot(&killedRobot);
        deathQueue.enqueue(killedRobot);
        killMsg << "<" << killedRobot->getCurrType() << " "
                << killedRobot->getRobotName() << "> will return in "
                << deathQueue.getSize() << " more turn(s)" << endl;
        killedRobot->resetKill();
    }
    else
    {
        killMsg << "<" << killedRobot->getCurrType() << " "
                << killedRobot->getRobotName() << "> has been executed" << endl;
        delete killedRobot;
        killedRobot = nullptr;
    }
    view->printAndLog(killMsg.str());

    robotGrid[y][x] = nullptr;
}

void SimulationController::displayKillCount(Robot *robot)
{
    view->displayKillCount(robot);
}

void SimulationController::upgradeRobot(Robot **robot)
{
    int robotX = (*robot)->getRobotPositionX();
    int robotY = (*robot)->getRobotPositionY();
    int robotId = (*robot)->getRobotId();
    string robotName = (*robot)->getRobotName();
    string initType = (*robot)->getInitType();
    string oldType = (*robot)->getCurrType();
    string robotChar = (*robot)->getRobotChar();

    if (oldType == "UltimateRobot")
        return;

    delete *robot;
    *robot = nullptr;
    robotGrid[robotY][robotX] = nullptr;

    if (oldType == "RoboCop" || oldType == "Terminator")
        *robot = robotFactory->getRobot("TerminatorRoboCop", robotName, robotX, robotY);
    else if (oldType == "BlueThunder")
        *robot = robotFactory->getRobot("Madbot", robotName, robotX, robotY);
    else if (oldType == "Madbot")
        *robot = robotFactory->getRobot("RoboTank", robotName, robotX, robotY);
    else if (oldType == "TerminatorRoboCop" || oldType == "RoboTank")
        *robot = robotFactory->getRobot("UltimateRobot", robotName, robotX, robotY);

    robotGrid[robotY][robotX] = *robot;
    (*robot)->setInitType(initType);
    (*robot)->setRobotId(robotId);
    (*robot)->setController(this);

    stringstream upgradeMsg;
    upgradeMsg << "<" << oldType << " " << (*robot)->getRobotName()
               << "> has been upgraded to <" << (*robot)->getCurrType()
               << " " << (*robot)->getRobotName() << ">" << endl;
    view->printAndLog(upgradeMsg.str());
}

void SimulationController::downgradeRobot(Robot **robot)
{
    int robotX = (*robot)->getRobotPositionX();
    int robotY = (*robot)->getRobotPositionY();
    int robotId = (*robot)->getRobotId();
    string robotName = (*robot)->getRobotName();
    string initType = (*robot)->getInitType();
    string oldType = (*robot)->getCurrType();
    string robotChar = (*robot)->getRobotChar();

    if (initType == "UltimateRobot" || oldType == initType)
        return;

    delete *robot;
    *robot = nullptr;
    robotGrid[robotY][robotX] = nullptr;

    *robot = robotFactory->getRobot(initType, robotName, robotX, robotY);

    robotGrid[robotY][robotX] = *robot;
    (*robot)->setInitType(initType);
    (*robot)->setRobotId(robotId);
    (*robot)->setController(this);

    stringstream downgradeStr;
    downgradeStr << "<" << oldType << " " << (*robot)->getRobotName()
                 << "> has been downgraded to <" << (*robot)->getCurrType()
                 << " " << (*robot)->getRobotName() << ">" << endl;
    view->printAndLog(downgradeStr.str());
}

void SimulationController::initSimulator(string filename)
{
    model->readFile(filename);
    deathQueue.setCapacity(model->getNumRobots());

    int M = model->getM();
    int N = model->getN();
    robotGrid = new Robot **[M];
    for (int i = 0; i < M; i++)
    {
        robotGrid[i] = new Robot *[N];
        for (int j = 0; j < N; j++)
            robotGrid[i][j] = nullptr;
    }

    view->displayFileData();
    updateBattlefield();

    view->printAndLog("Generating Robots...\n");
    generateRobots();
    Node *currPtr = turnList.getFirst(),
         *startPtr = currPtr;
    do
    {
        view->displayRobotInfo(currPtr->data);
        currPtr = currPtr->next;
    } while (currPtr != startPtr);
    updateBattlefield();
}

// RUN SIMULATION
void SimulationController::runSimulator(string filename)
{
    view->printAndLog("Initializing Simulation...\n");
    initSimulator(filename);

    view->printAndLog("\n***** Simulation Starts Now *****\n");
    Node *currPtr = turnList.getFirst();
    while (stepCount++ < model->getSteps() && Robot::getRobotCount() != 1)
    {
        view->displayTurn();

        if (!deathQueue.empty())
        {
            Robot *returnRobot = deathQueue.front();
            string returnMessage = "<" + returnRobot->getCurrType() + " " + returnRobot->getRobotName() + "> has returned to battlefield\n";
            deathQueue.dequeue();

            int randX, randY;
            do
            {
                randX = rand() % getN();
                randY = rand() % getM();
            } while (robotGrid[randY][randX] != nullptr);

            returnRobot->setRobotPositionX(randX);
            returnRobot->setRobotPositionY(randY);

            turnList.push_back(returnRobot);
            robotGrid[randY][randX] = returnRobot;
            returnMessage += "Return position: (" + to_string(randX) + ", " + to_string(randY) + ")\n\n";
            view->printAndLog(returnMessage);
        }

        updateBattlefield();
        view->displayRobotInfo(currPtr->data);
        view->displayKillCount(currPtr->data);

        currPtr->data->action();

        if (currPtr->data->getKillCount() >= 3)
        {
            upgradeRobot(&currPtr->data);
            view->displayRobotInfo(currPtr->data);
            currPtr->data->resetKill();
        }

        currPtr = currPtr->next;
    }

    if (Robot::getRobotCount() == 1)
    {
        view->printAndLog("\nLeft only one robot in battlefield, simulation ends");
        view->printAndLog("\nThe winner is ...");
        view->displayRobotInfo(turnList.getFirst()->data);
    }
    else
    {
        view->printAndLog("\nSteps are over, simulation ends");
        view->printAndLog("\nRemaining robots ...");

        Node *currPtr = turnList.getFirst(),
             *startPtr = currPtr;
        do
        {
            view->displayRobotInfo(currPtr->data);
            currPtr = currPtr->next;
        } while (currPtr != startPtr);
    }
}
