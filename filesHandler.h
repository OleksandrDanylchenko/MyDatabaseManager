#include <stdio.h>

#ifndef DATABASES_FILESHANDLER_H
#define DATABASES_FILESHANDLER_H

void openShopsDataFile(FILE **file);

void openShopsIndicesFile(FILE **file);

void openEmployeesDataFile(FILE **file);

void openEmployeesIndicesFile(FILE **file);

void openFile(FILE **file, char *path);

#endif //DATABASES_FILESHANDLER_H