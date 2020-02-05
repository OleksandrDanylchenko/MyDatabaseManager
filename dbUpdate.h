#ifndef DATABASES_DBUPDATE_H
#define DATABASES_DBUPDATE_H

#include "dbStructures.h"

void updateM();

void updateShopEmployeeId(shop changeShop, int newEmployeeId);

void updateS();

void updateShopToInactive(shop delShop);

void updateEmployeeToInactive(employee delEmployee);

void updateTrashZone(trashZone trashZoneData);

#endif // DATABASES_DBUPDATE_H