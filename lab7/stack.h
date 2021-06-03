#ifndef STACK_H
#define STACK_H
#include <QString>
#include <QVector>

struct Node
{
    int data;
    int key;
    Node* next = nullptr;
};

class Stack
{
public:
    Node* head;
    Node* tail;

    int temp = 0;
    Stack()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(int key, int data)
    {
        Node* item = new Node;
        item->data = data;
        item->key = key;

        if(!head)
        {
            head = item;
            tail = item;
            item = nullptr;
            delete item;
        }
        else
        {
            tail->next = item;
            tail = item;
            item = nullptr;
            delete item;
        }
    }

    QString show(QVector<int> *arrData, QVector<int> *arrKey)
    {
        if(!head) return "";
        Node* current = head;
        QString result = "";
        for(int i = 0; current != nullptr; i++)
        {
            if(i) result += "-->";
            result += QString::number(current->data);
            arrData->append(current->data);
            arrKey->append(current->key);
            current = current->next;
        }
        delete current;
        return result;
    }
    QString show()
    {
        if(!head) return "";
        Node* current = head;
        QString result = "";
        for(int i = 0; current != nullptr; i++)
        {
            if(i) result += "-->";
            result += QString::number(current->data);
            current = current->next;
        }
        delete current;
        return result;
    }

    void pop()
    {
        if(!head) return;
        if(head == tail)
        {
            head = tail = nullptr;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while(current != tail)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        tail->next = nullptr;
        delete current;
    }

    bool contain(int key)
    {
        Node* tmp = head;
        while(tmp)
        {
            if(tmp->key == key)
                return true;
            else
                tmp = tmp->next;
        }
        return false;
    }

    int search(int key)
    {
        if(!head) return -1;
        Node* current = head;
        while(current != nullptr)
        {
            if(current->key == key)
                return current->data;
            current = current->next;
        }
        return -1;
    }

    void free()
    {
        while(head) pop();
    }
};

#endif // STACK_H
