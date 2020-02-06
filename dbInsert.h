#ifndef DATABASES_DBINSERT_H
#define DATABASES_DBINSERT_H

#include "dbFilesHandler.h"
#include "dbStructures.h"
#include <stdbool.h>

void insertM();

void insertS();

bool validateRecordsAmount(dbFiles fileType);

shop getNewShopRecord();

employee getNewEmployeeRecord(shop mShop);

keyIndex getNewDataIndex(dbFiles fileType);

void insertNewShopRecord(int id);

void insertNewShopIndex();

void insertNewEmployeeRecord(shop mShop, int id);

void insertNewEmployeeIndex();

#endif // DATABASES_DBINSERT_H