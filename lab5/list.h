#ifndef LIST_H
#define LIST_H
#include <QImage>
#include "queue.h"

class list : public queue
{
public:
    Node* head;
    Node* tail;

    list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(Node*& temp)
    {
        if(!head)
        {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            tail->next = head;
            head->prev = tail;
        }
    }

    Node* leftToRight(Node* item)
    {
        if(!head) return item;
        Node* current = head;
        while(current->image != item->image)
            current = current->next;

        current = current->next;
        return current;
    }

    Node* rightToLeft(Node* item)
    {
        if(!head) return item;
        Node* current = tail;
        while(current->image != item->image)
            current = current->prev;
        current = current->prev;
        return current;
    }

    void pop(Node* item)
    {

        if(!head) return;
        if(head == tail)
        {
            if(head->image == item->image)
                head = tail = nullptr;

            delete item;
            return;
        }

        bool f = false;
        Node* current = head;
        while(current->image != item->image && !(current == head && f))
        {
            f = true;
            current = current->next;
        }

        delete item;

        if(current == head && f)
            return;
        if(current == head)
            head = current->next;
        if(current == tail)
            tail = current->prev;

        current->next->prev = current->prev;
        current->prev->next = current->next;

        delete  current;
        return;
    }
};

#endif // LIST_H
