/*
 * This is a simple integer Hash Table demo using linear probing.
 */

/* 
 * File:   main.cpp
 * Author: Alex Katrompas
 */

#include "hashtable.h"

/************************************
 * Constructor / Destructor
 ************************************/

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = 0; // assume an id must be > 0
    }
}

Hashtable::~Hashtable() {
    // nothing to do here
}


/************************************
 * Private
 ************************************/
int Hashtable::hash(int id) {
    // guarantees a position between 0 and HASHTABLESIZE - 1
    return id % HASHTABLESIZE;
}


/************************************
 * Public
 ************************************/

bool Hashtable::insertEntry(int id) {
    bool inserted = false;
    int position = hash(id);
    
    cout << id << " initial position: " << position << ", ";
    // if the space is occupied, search for the next space
    // this is a linear probe
    if (hashtable[position]) {
        for (int i = 0; i < HASHTABLESIZE && hashtable[position]; i++) {
            if (position == HASHTABLESIZE - 1) {
                position = 0;
            } else {
                position++;
            }
            cout << position << ", ";
        }
    }
    cout << "final: " << position << endl;

    // if the space is empty, insert, otherwise the table was full
    if (!hashtable[position]) {
        hashtable[position] = id;
        count++;
        inserted = true;
    }
    
    return inserted;
}

bool Hashtable::deleteEntry(int id) {
    bool deleted = false;
    int position = hash(id);

    /*
     * Start at the hashed position and then linear probe
     */
    for (int i = 0; i < HASHTABLESIZE && !deleted; i++) {
        if (hashtable[position] && hashtable[position] == id) {
            hashtable[position] = 0;
            deleted = true;
        } else {
            if (position == HASHTABLESIZE - 1) {
                position = 0;
            } else {
                position++;
            }
        }
    }

    return deleted;
}

int Hashtable::getEntry(int id) {
    int ret = 0;
    int position = hash(id);

    /*
     * Start at the hashed position and then linear probe
     */
    for (int i = 0; i < HASHTABLESIZE && !ret; i++) {
        if (hashtable[position] && hashtable[position] == id) {
            ret = hashtable[position];
        } else {
            if (position == HASHTABLESIZE - 1) {
                position = 0;
            } else {
                position++;
            }
        }
    }

    return ret;
}

void Hashtable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]) {
            cout << "Table Entry " << i << ": " << hashtable[i] << endl;
        } else {
            cout << "Table Entry " << i << ": EMPTY" << endl;
        }
    }
}

int Hashtable::getCount() {
    return count;
}
