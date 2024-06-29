#include "RobotFactory.h"
#include "RoboCop.h"
#include "Terminator.h"
#include "BlueThunder.h"
#include "TerminatorRoboCop.h"
#include "Madbot.h"
#include "RoboTank.h"
#include "UltimateRobot.h"

Robot *RobotFactory::getRobot(string type, string name, int x, int y)
{
    Robot *newRobot = nullptr;
    if (type == "RoboCop")
        newRobot = new RoboCop(name, x, y);
    else if (type == "Terminator")
        newRobot = new Terminator(name, x, y);
    else if (type == "TerminatorRoboCop")
        newRobot = new TerminatorRoboCop(name, x, y);
    else if (type == "BlueThunder")
        newRobot = new BlueThunder(name, x, y);
    else if (type == "Madbot")
        newRobot = new Madbot(name, x, y);
    else if (type == "RoboTank")
        newRobot = new RoboTank(name, x, y);
    else if (type == "UltimateRobot")
        newRobot = new UltimateRobot(name, x, y);

    return newRobot;
}
