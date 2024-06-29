#include "Logger.h"

Logger::~Logger()
{
    logFile << "\n~~~~~ RobotWar Simulator Log End ~~~~~" << endl;
    logFile.close();
}

void Logger::log(const string &logMessage)
{
    if (logFile.is_open())
        logFile << logMessage << endl;
}

void Logger::logToFile(const string &filename)
{
    logFile.open(filename, ios::trunc);
    logFile.close();

    logFile.open(filename, ios::app);
    logFile << "~~~~~ RobotWar Simulator Log ~~~~~\n"
            << endl;
}
