/**********|**********|**********|
Program: RoboCop.cpp
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

#include "RoboCop.h"
void RoboCop::action()
{
    look(0, 0);
    move(decidedX, decidedY);

    int fireX = -1, fireY = -1,
        maxRange = 10, rangeLeft = maxRange,
        fireCount = 0;
    do
    {
        fireX = rand() % 21 - maxRange;

        int rangeLeft = maxRange - abs(fireX);
        fireY = rand() % (2 * rangeLeft + 1) - rangeLeft;

        if ((fireX != 0 || fireY != 0) && !controller->checkBoundary(fireX + getRobotPositionX(), fireY + getRobotPositionY()))
        {
            fire(fireX, fireY);
            fireCount++;
        }
    } while (fireCount < 3);

    controller->updateBattlefield();
}
