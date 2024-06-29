#include <iomanip>
#include <sstream>

#include "Robot.h"
#include "SimulationView.h"

void SimulationView::setController(SimulationController *c)
{
    controller = c;
}

void SimulationView::setLogger(Logger *l)
{
    logger = l;
}

void SimulationView::print(string message)
{
    cout << message << endl;
}

void SimulationView::log(string message)
{
    logger->log(message);
}

void SimulationView::printAndLog(string message)
{
    cout << message << endl;
    logger->log(message);
}

void SimulationView::displayFileData()
{
    stringstream dataStr;
    dataStr << "Arena Size:\t" << controller->getM()
            << " x " << controller->getN() << endl;
    dataStr << "Robot Number:\t" << controller->getNumRobots() << endl;
    dataStr << "Steps:\t\t" << controller->getSteps() << endl;
    dataStr << "\nParticipant Robots: -" << endl;
    for (int i = 0; i < controller->getNumRobots(); i++)
    {
        dataStr << "Robot #" << i + 1 << ": " << setw(10) << left << controller->getRobotNames()[i]
                << "Type: " << setw(20) << controller->getRobotTypes()[i] << "Position: (" << controller->getRobotXs()[i]
                << ", " << controller->getRobotYs()[i] << ")" << endl;
    }
    printAndLog(dataStr.str());
}

void SimulationView::displayRobotInfo(Robot *robot)
{
    stringstream robotInfo;
    robotInfo << "Robot #" << robot->getRobotId() << ": "
              << setw(6) << left << robot->getRobotName() << "  "
              << "Robot Character: " << setw(6) << left << robot->getRobotChar() << "  "
              << "Type: " << setw(10) << left << robot->getCurrType() << "  "
              << "Position: (" << robot->getRobotPositionX() << ", " << robot->getRobotPositionY() << ")";
    printAndLog(robotInfo.str());
}

void SimulationView::displayBattlefield(Robot ***robotGrid)
{
    stringstream battlefieldStr;

    int indent = 4,
        charLen = 3,
        M = controller->getM(),
        N = controller->getN(),
        columnSpacing = 3,
        rowSpacing = 1;
    char leftRightBoundary = '|',
         topBottomBoundary = '+';
    string empty = "***";

    int topBottomBoundaryNum = charLen * N + columnSpacing * (N + 1) + 2;

    // Coordinate system
    battlefieldStr << endl;
    battlefieldStr << string(indent + columnSpacing + (charLen + 1) / 2, ' ');
    for (int col = 0; col < N; col++)
        battlefieldStr << setw(columnSpacing + charLen) << left << col;
    battlefieldStr << endl;

    // Top Boundary
    battlefieldStr << string(indent, ' ');
    for (int i = 0; i < topBottomBoundaryNum; i++)
        battlefieldStr << topBottomBoundary;
    battlefieldStr << endl;

    // Left & Right Boundary and Contents
    for (int row = 0; row < M; row++)
    {
        battlefieldStr << setw(indent - 1) << row << " ";

        battlefieldStr << leftRightBoundary;
        for (int col = 0; col < N; col++)
        {
            if (robotGrid[row][col] == nullptr)
                battlefieldStr << string(columnSpacing, ' ') << empty;
            else
                battlefieldStr << string(columnSpacing, ' ') << robotGrid[row][col]->getRobotChar();
        }
        battlefieldStr << string(columnSpacing, ' ');
        battlefieldStr << leftRightBoundary << endl;

        if (row != M - 1 && rowSpacing > 0)
        {
            for (int i = 0; i < rowSpacing; i++)
            {
                battlefieldStr << string(indent, ' ');
                battlefieldStr << leftRightBoundary << string(topBottomBoundaryNum - 2, ' ')
                               << leftRightBoundary;
                battlefieldStr << endl;
            }
        }
    }

    // Bottom Boundary
    battlefieldStr << string(indent, ' ');
    for (int i = 0; i < topBottomBoundaryNum; i++)
        battlefieldStr << topBottomBoundary;
    battlefieldStr << endl;

    controller->displayMessage(battlefieldStr.str());
}

void SimulationView::displayTurn()
{
    stringstream turnStr;
    turnStr << "\n------- Turn "
            << controller->getStepCount()
            << " -------\n";
    printAndLog(turnStr.str());
}

void SimulationView::displayKillCount(Robot *robot)
{
    stringstream killInfo;
    killInfo << "-- Kill Count: " << robot->getKillCount() << endl;
    printAndLog(killInfo.str());
}
