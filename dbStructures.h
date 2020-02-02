#ifndef DATABASES_DBSTRUCTURES_H
#define DATABASES_DBSTRUCTURES_H

#define MAX_AMOUNT 20

typedef struct shop {
    int id;
    char *address;
} shop;

typedef struct employee {
    int id;
    int shopId;
    char *post;
    char *FirstName;
    char *LastName;
} employee;

typedef struct keyIndex {
    int key;
    long index;
} keyIndex;

#endif //DATABASES_DBSTRUCTURES_H