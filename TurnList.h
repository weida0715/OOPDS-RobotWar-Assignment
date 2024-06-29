#include <iostream>
using namespace std;

#pragma once

class Robot;

class Node
{
public:
    Robot *data;
    Node *next;

    Node(Robot *value, Node *link = nullptr)
        : data(value), next(link) {}
};

class TurnList
{
public:
    TurnList();
    // TurnList(const TurnList &origList);
    ~TurnList();

    // const TurnList &operator=(const TurnList &rightHandSide);
    Node *getFirst();
    Node *getLast();
    int getSize() const;
    bool empty() const;
    void display(ostream &out) const;
    void push_back(Robot *&item);
    void remove(Robot *item);
    // Robot* pop(Robot* item);

private:
    Node *last;
    int mySize;
};

ostream &operator<<(ostream &out, const TurnList &aList);
