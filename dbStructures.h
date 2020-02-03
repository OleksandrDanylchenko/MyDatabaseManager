#ifndef DATABASES_DBSTRUCTURES_H
#define DATABASES_DBSTRUCTURES_H

#define MAX_AMOUNT 20

#pragma pack(1)
typedef struct shop {
    int id;
    char address[70];
    bool isActive;
} shop;

#pragma pack(1)
typedef struct employee {
    int id;
    int shopId;
    char post[50];
    char FirstName[50];
    char LastName[50];
    bool isActive;
} employee;

#pragma pack(1)
typedef struct keyIndex {
    int key;
    unsigned long address;
} keyIndex;

#endif //DATABASES_DBSTRUCTURES_H