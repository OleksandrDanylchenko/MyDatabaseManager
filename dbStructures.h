#ifndef DATABASES_DBSTRUCTURES_H
#define DATABASES_DBSTRUCTURES_H

#define MAX_AMOUNT 20

typedef struct shop {
    int id;
    char *address;
    bool isActive;
} shop;

typedef struct employee {
    int id;
    int shopId;
    char *post;
    char *FirstName;
    char *LastName;
    bool isActive;
} employee;

typedef struct keyIndex {
    int key;
    unsigned long address;
} keyIndex;

#endif //DATABASES_DBSTRUCTURES_H