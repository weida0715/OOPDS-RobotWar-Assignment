/**********|**********|**********|
Program: main.cpp
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

#include "SimulationModel.h"
#include "SimulationView.h"
#include "SimulationController.h"

int main(int argc, char *argv[])
{

    string inputFile = "input.txt",
           outputFile = "output.txt";

    SimulationModel model;
    SimulationView view;
    SimulationController controller(&model, &view);

    controller.logToFile(outputFile);
    controller.runSimulator(inputFile);

    return 0;
}
