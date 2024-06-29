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
