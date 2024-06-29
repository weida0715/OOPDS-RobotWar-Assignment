#include <fstream>
#include <sstream>
#include "SimulationModel.h"

// --- Default Constructor ---
SimulationModel::SimulationModel() : M(0), N(0), steps(0), numRobots(0),
                                     robotNames(nullptr), robotTypes(nullptr),
                                     robotXs(nullptr), robotYs(nullptr) {}

// --- Destructor ---
SimulationModel::~SimulationModel()
{
    delete[] robotNames;
    delete[] robotTypes;
    delete[] robotXs;
    delete[] robotYs;
}

// --- Getters ---
int SimulationModel::getM() const { return M; }
int SimulationModel::getN() const { return N; }
int SimulationModel::getSteps() const { return steps; }
int SimulationModel::getNumRobots() const { return numRobots; }
string *SimulationModel::getRobotNames() const { return robotNames; }
string *SimulationModel::getRobotTypes() const { return robotTypes; }
string *SimulationModel::getRobotXs() const { return robotXs; }
string *SimulationModel::getRobotYs() const { return robotYs; }

// --- Member Functions ---
void SimulationModel::readFile(string filename)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit(-1);
    }

    string temp, line;
    getline(inputFile, line);
    {
        stringstream ss(line);
        ss >> temp >> temp >> temp >> M >> N;
    }

    getline(inputFile, line);
    line.erase(0, line.find(":") + 1);
    {
        stringstream ss(line);
        ss >> steps;
    }

    getline(inputFile, line);
    line.erase(0, line.find(":") + 1);
    {
        stringstream ss(line);
        ss >> numRobots;
    }

    robotTypes = new string[numRobots];
    robotNames = new string[numRobots];
    robotXs = new string[numRobots];
    robotYs = new string[numRobots];

    for (int i = 0; i < numRobots; i++)
    {
        getline(inputFile, line);
        stringstream iss(line);
        iss >> robotTypes[i] >> robotNames[i] >> robotXs[i] >> robotYs[i];
    }

    inputFile.close();
}
