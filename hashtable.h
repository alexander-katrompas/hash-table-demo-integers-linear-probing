/*
 * This is a simple integer Hash Table demo using linear probing.
 */

/* 
 * File:   main.cpp
 * Author: Alex Katrompas
 */

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class Hashtable {

public:
    Hashtable();
    ~Hashtable();
    
    bool insertEntry(int);
    int getEntry(int);
    bool deleteEntry(int);
    int getCount();
    void printTable();

    private:

    int hash(int);
    int count;
    int hashtable[HASHTABLESIZE];
};

#endif /* HASHTABLE_HASHTABLE_H */

