#ifndef DATABASES_DBDELETION_H
#define DATABASES_DBDELETION_H

#pragma pack(1)
#include "dbFilesHandler.h"
#include "dbStructures.h"

void delM();

void delS();

int *markShopEmployeesInactive(shop delShop);

int getTrashKeysAmount(dbFiles fileType);

#endif // DATABASES_DBDELETION_H