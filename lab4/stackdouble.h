#ifndef STACKDOUBLE_H
#define STACKDOUBLE_H

struct nodeDouble
{
    double operation;
    nodeDouble* next = nullptr;
};

class StackDouble
{
public:
    nodeDouble* head;
    nodeDouble* tail;
    StackDouble()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(double oper)
    {
        nodeDouble *temp = new nodeDouble;
        temp->operation = oper;
        temp->next = nullptr;

        if(!head)
        {
            head = temp;
            tail = temp;
            temp = nullptr;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    double pop()
    {
        double oper;
        nodeDouble *current = head;
        nodeDouble *previous = nullptr;
        while (current->next)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = nullptr;
        oper = current->operation;
        delete current;
        return oper;
    }

};



#endif // STACKDOUBLE_H
