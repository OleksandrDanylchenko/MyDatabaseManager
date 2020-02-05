#ifndef DATABASES_DBUPDATE_H
#define DATABASES_DBUPDATE_H

#include "dbStructures.h"

void updateM();

void updateShopEmployeeId(shop changeShop, int newEmployeeId);

void updateS();

// TODO
void markShopInactive(shop delShop);

// TODO
void markEmployeeInactive(employee delEmployee);

#endif // DATABASES_DBUPDATE_H