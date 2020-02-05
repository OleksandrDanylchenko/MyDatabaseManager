#ifndef DATABASES_DBREAD_H
#define DATABASES_DBREAD_H

#include "dbFilesHandler.h"
#include "dbStructures.h"

shop getM();

employee getS();

void getAll();

int getUserKey(dbFiles fileType);

void readIndices(keyIndex *indices, int size, dbFiles fileType);

unsigned long getAddressByKey(int key, dbFiles fileType);

shop getShopByKey(int userKey);

employee getEmployeeByKey(int userKey);

void formatShopOutput(shop outShop);

void formatEmployeeOutput(employee outEmployee);

int getRecordsNum(dbFiles fileType);

trashZone getTrashZoneData();

#endif // DATABASES_DBREAD_H