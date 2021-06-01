#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "hashtable.h"
#include "stack.h"
#include <QString>

class myHashTable : public hashTable
{
public:
    myHashTable() : hashTable(){}
    myHashTable(int n) : hashTable(n){}


};

#endif // MYHASHTABLE_H
