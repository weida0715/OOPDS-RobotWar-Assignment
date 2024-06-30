/**********|**********|**********|
Program: SimulationModel.h
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
