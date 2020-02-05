#ifndef DATABASES_DBREAD_H
#define DATABASES_DBREAD_H

#include "dbFilesHandler.h"
#include "dbStructures.h"

shop getM();

employee getS();

void getAll();

int getUserKey(dbFiles fileType);

void readIndices(keyIndex *indices, int size, dbFiles fileType);

unsigned long getAddressByKey(int userKey, dbFiles fileType);

shop getShopByKey(int userKey);

employee getEmployeeByKey(int userKey);

void formatShopOutput(shop outShop);

void formatEmployeeOutput(employee outEmployee);

int getRecordsNum(dbFiles fileType);

int getTrashZoneData(dbFiles fileType);

#endif // DATABASES_DBREAD_H