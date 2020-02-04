#ifndef DATABASES_DBSTRUCTURES_H
#define DATABASES_DBSTRUCTURES_H

#define MAX_AMOUNT 20

#pragma pack(1)
typedef struct shop {
  int id;
  char address[70];
  bool isActive;
  int employeeId;
} shop;

#pragma pack(1)
typedef struct employee {
  int id;
  char firstName[50];
  char lastName[50];
  int colleagueId;
  bool isActive;
} employee;

#pragma pack(1)
typedef struct keyIndex {
  int key;
  unsigned long address;
} keyIndex;

#endif // DATABASES_DBSTRUCTURES_H