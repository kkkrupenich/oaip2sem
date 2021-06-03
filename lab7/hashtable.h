#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "stack.h"

class hashTable
{
public:
    QVector<int> arrData;
    QVector<int> arrKey;
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
    void add(int key, int data)
    {
        int n = GetHash(key);
        if(!array[n].contain(key))
            array[n].push(key, data);
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
            result += QString::number(i) + " : " + array[i].show(&arrData, &arrKey) + '\n';
        return result;
    }

    int search(int key)
    {
        for(int i = 0; i < size; i++)
        {
            int data = array[i].search(key);
            if(data != -1)
                return data;
        }
        return -1;
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
    int GetHash(int key)
    {
        return key % size;
    }
};

#endif // HASHTABLE_H
