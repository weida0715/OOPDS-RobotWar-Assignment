/**********|**********|**********|
Program: DeathQueue.cpp
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

#include "DeathQueue.h"

DeathQueue::DeathQueue(int capacity) : myCapacity(capacity) {}

void DeathQueue::setCapacity(int capacity)
{
    myCapacity = capacity;
    if (myDeque.size() > static_cast<size_t>(myCapacity))
        myDeque.resize(myCapacity);
}

bool DeathQueue::empty() const
{
    return myDeque.empty();
}

void DeathQueue::enqueue(Robot *value)
{
    if (myDeque.size() < static_cast<size_t>(myCapacity))
        myDeque.push_back(value);
    else
        cerr << "*** DeathQueue full -- can't add new value ***\n";
}

void DeathQueue::dequeue()
{
    if (!empty())
        myDeque.pop_front();
    else
        cerr << "*** DeathQueue is empty -- can't remove a value ***\n";
}

int DeathQueue::getSize() const
{
    return static_cast<int>(myDeque.size());
}

Robot *DeathQueue::front() const
{
    if (!empty())
        return myDeque.front();
    else
    {
        cerr << "*** DeathQueue is empty -- returning nullptr ***\n";
        return nullptr;
    }
}
