#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#pragma once

class Robot;

class DeathQueue {
private:
    deque<Robot*> myDeque;
    int myCapacity;

public:
    DeathQueue(int capacity = 5);
    void setCapacity(int capacity);
    bool empty() const;
    void enqueue(Robot* value);
    void dequeue();
    int getSize() const;
    Robot* front() const;
};
