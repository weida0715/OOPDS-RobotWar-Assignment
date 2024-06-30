/**********|**********|**********|
Program: TurnList.h
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
