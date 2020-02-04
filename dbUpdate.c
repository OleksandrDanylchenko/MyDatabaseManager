#pragma pack(1)
#include "dbFilesHandler.h"
#include "dbRead.h"
#include "dbStructures.h"
#include <stdio.h>

// TODO
void updateM() {}
// TODO
void updateShopEmployeeId(shop changeShop, int newEmployeeId) {
  changeShop.employeeId = newEmployeeId;
  FILE *shopDataFile;
  openDbFile(&shopDataFile, shopData);
  unsigned long shopAddress = getAddressByKey(changeShop.id - 1, shopsData);
  fseek(shopDataFile, (long)shopAddress, SEEK_SET);
  fwrite(&changeShop, sizeof(shop), 1, shopDataFile);
  fclose(shopDataFile);
}

// TODO
void updateS() {}