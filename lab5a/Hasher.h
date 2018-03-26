#ifndef HASHER_H
#define HASHER_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// public portion of Hasher defintion
typedef struct Hasher {
    int (*hash)(char *val);
} Hasher;

// the function that preforms the hash algorithm
int hash(char *val); 

// allocates a hasher object to the heap
Hasher *createHasher();

void cleanup(Hasher *h);

#endif
