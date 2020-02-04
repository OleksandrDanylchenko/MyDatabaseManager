#ifndef DATABASES_DBREAD_H
#define DATABASES_DBREAD_H

#include "dbFilesHandler.h"
#include "dbStructures.h"

shop getM();

void getS();

void getAll();

int getKeyFromUser();

bool readIndices(keyIndex *indices, int size, dbFiles fileType);

unsigned long getAddressByKey(keyIndex *indices, int arrSize, int userKey,
                    dbFiles fileType);

shop getShopByKey(keyIndex *indices, int arrSize, int userKey);

#endif // DATABASES_DBREAD_H