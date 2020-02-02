#include <stdio.h>

#ifndef DATABASES_FILESHANDLER_H
#define DATABASES_FILESHANDLER_H

typedef enum dbFiles {
    ShopsData,
    ShopsIndices,
    EmployeesData,
    EmployeesIndices
} dbFiles;

void openDbFile(FILE **file, dbFiles dbFileType);

#endif //DATABASES_FILESHANDLER_H