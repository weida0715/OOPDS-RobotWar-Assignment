#include <iostream>
using namespace std;

#pragma once

class SimulationModel
{
private:
    // Data Members
    int M, N;
    int steps;
    int numRobots;
    string *robotNames,
        *robotTypes,
        *robotXs,
        *robotYs;

public:
    // Constructors & Destructors
    SimulationModel();
    ~SimulationModel();

    // Getters
    int getM() const;
    int getN() const;
    int getSteps() const;
    int getNumRobots() const;
    string *getRobotNames() const;
    string *getRobotTypes() const;
    string *getRobotXs() const;
    string *getRobotYs() const;

    // Member Functions
    void readFile(string fileName);
};
