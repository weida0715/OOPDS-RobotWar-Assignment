#include "TurnList.h"

TurnList::TurnList()
    : last(nullptr), mySize(0)
{
}

TurnList::~TurnList()
{
    while (!empty())
    {
        Node *first = last->next;
        if (first == last)
        {
            delete first;
            last = nullptr;
        }
        else
        {
            last->next = first->next;
            delete first;
        }
        mySize--;
    }
}

Node *TurnList::getFirst()
{
    return last->next;
}

Node *TurnList::getLast()
{
    return last;
}

int TurnList::getSize() const
{
    return mySize;
}

bool TurnList::empty() const
{
    return mySize == 0;
}

void TurnList::push_back(Robot *&item)
{
    Node *newNode = new Node(item);
    if (last == nullptr)
    {
        last = newNode;
        last->next = last; // Point to itself in case of single node
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    mySize++;
}

void TurnList::remove(Robot *item)
{
    if (mySize == 0)
    {
        cout << "*** List is empty ***\n";
        return;
    }
    Node *currPtr = last->next,
         *prevPtr = last;
    do
    {
        if (currPtr->data == item)
        {
            if (mySize == 1)
            {
                delete currPtr;
                last = nullptr;
            }
            else
            {
                prevPtr->next = currPtr->next;
                if (currPtr == last)
                    last = prevPtr;
                delete currPtr;
            }
            mySize--;
            return;
        }
        prevPtr = currPtr;
        currPtr = currPtr->next;
    } while (currPtr != last->next);
    cout << "*** Value not found in the list. List unchanged. ***\n";
}

// Robot *TurnList::pop(Robot *item)
// {
//     if (mySize == 0)
//     {
//         cerr << "*** List is empty ***\n";
//         return;
//     }

//     Node *currPtr = last->next,
//          *prevPtr = last,
//          *startPtr = currPtr;
//     do
//     {
//         Robot* poppedItem = 
//         if (currPtr->data == item)
//         {

//         }
//     } while (currPtr != startPtr);
// }

void TurnList::display(ostream &out) const
{
    if (!empty())
    {
        Node *ptr = last->next;
        do
        {
            out << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != last->next);
    }
    else
        cout << "*** List is empty ***\n";
}

ostream &operator<<(ostream &out, const TurnList &aList)
{
    aList.display(out);
    return out;
}
