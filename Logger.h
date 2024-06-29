#include <iostream>
#include <fstream>
using namespace std;

#pragma once

class Logger
{
private:
    ofstream logFile;

public:
    Logger() = default;
    ~Logger();

    void logToFile(const string &filename);
    void log(const string &logMessage);
};
