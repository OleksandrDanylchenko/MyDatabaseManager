#ifndef DATABASES_DBDELETION_H
#define DATABASES_DBDELETION_H

#pragma pack(1)
#include "dbFilesHandler.h"
#include "dbStructures.h"

void delM();

void delS();

void markShopEmployeesInactive(trashZoneData *trashZone, shop delShop);



#endif // DATABASES_DBDELETION_H