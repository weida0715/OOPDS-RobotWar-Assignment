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
