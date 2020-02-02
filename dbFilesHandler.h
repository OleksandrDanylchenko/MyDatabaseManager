#include <stdio.h>

#ifndef DATABASES_FILESHANDLER_H
#define DATABASES_FILESHANDLER_H

typedef enum dbFiles {
    shopsData,
    shopsIndices,
    employeesData,
    employeesIndices
} dbFiles;

const char* fileNames[] = {"Shops.fl", "Shops.ind", "Employees.fl", "Employees.ind"};

void openDbFile(FILE **file, dbFiles fileType);
int getRecordsAmount(dbFiles fileType);

#endif //DATABASES_FILESHANDLER_H