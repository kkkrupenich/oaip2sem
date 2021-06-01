#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "stack.h"

class hashTable
{
public:
    QVector<int> arr;
    hashTable()
    {
        array = new Stack[10];
        size = 10;
    }
    hashTable(int n)
    {
        array = new Stack[n];
        size = n;
    }
    void add(int data)
    {
        int n = GetHash(data);
        if(!array[n].contain(data))
            array[n].push(data);
    }
    void remove(int index)
    {
        if(index > size) return;
        array[index].pop();
    }
    QString show()
    {
        QString result = "";
        for(int i = 0; i < size; i++)
            result += QString::number(i) + " : " + array[i].show(&arr) + '\n';
        return result;
    }
    QString showTwo()
    {
        QString result = "";
        for(int i = 0; i < size; i++)
            result += QString::number(i) + " : " + array[i].show() + '\n';
        return result;
    }
    void free()
    {
        for(int i = 0; i < size; i++)
            array[i].free();
    }
protected:
    Stack *array;
    int size;
    int GetHash(int data)
    {
        return data % size;
    }
};

#endif // HASHTABLE_H
