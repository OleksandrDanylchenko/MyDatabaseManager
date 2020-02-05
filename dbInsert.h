#ifndef DATABASES_DBINSERT_H
#define DATABASES_DBINSERT_H

#include "dbFilesHandler.h"
#include "dbStructures.h"
#include <stdbool.h>

void insertM();

void insertS();

bool validateRecordsAmount(dbFiles fileType);

shop getNewShopRecord();

employee getNewEmployeeRecord(int colleagueId);

keyIndex getNewDataIndex(dbFiles fileType);

#endif // DATABASES_DBINSERT_H