#ifndef DATABASES_DBUPDATE_H
#define DATABASES_DBUPDATE_H

#include "dbStructures.h"

void updateM();

void updateShopEmployeeId(shop changeShop, int newEmployeeId);

void updateS();

// TODO
void writeShopInactive(shop delShop);

// TODO
void writeEmployeeInactive(employee delEmployee);

#endif // DATABASES_DBUPDATE_H