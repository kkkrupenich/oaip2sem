#ifndef QUEUE_H
#define QUEUE_H
#include <QImage>

struct Node
{
    QImage image;
    int queueItem;
    Node* next;
    Node* prev;

    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
};

class queue
{
public:
    Node* head;
    Node* tail;

    queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        if(!head)
            return true;
        else
            return false;
    }

    void push(Node* item)
    {
        if(!head)
        {
            head = item;
            tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
    }
    int pop()
    {
        if(!head) return 0;
        if (tail == head)
        {
            int item;
            item = tail->queueItem;
            tail = head = nullptr;
            return item;
        }

        int item;
        item = head->queueItem;
        head = head->next;
        return item;
    }

};

#endif // QUEUE_H
