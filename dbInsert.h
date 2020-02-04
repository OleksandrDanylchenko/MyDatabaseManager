#ifndef DATABASES_DBINSERT_H
#define DATABASES_DBINSERT_H

#include <stdbool.h>
#include "dbFilesHandler.h"
#include "dbStructures.h"

void insertM();

void insertS();

bool validateRecordsAmount(dbFiles fileType);

shop getNewShopRecord();

keyIndex getNewDataIndex(dbFiles fileType);

#endif //DATABASES_DBINSERT_H