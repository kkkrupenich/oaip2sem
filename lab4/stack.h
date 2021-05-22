#ifndef STACK_H
#define STACK_H

struct node
{
    char operation;
    node* next = nullptr;
};

class Stack
{
public:
    node* head;
    node* tail;
    Stack()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(char oper)
    {
        node *temp = new node;
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

    char pop()
    {
        char oper;
        node *current = head;
        node *previous = nullptr;
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

#endif // STACK_H
