#pragma pack(1)
#include "dbFilesHandler.h"
#include "dbRead.h"
#include "dbStructures.h"
#include <stdio.h>

// TODO
void updateM() {
  printf("Old values are: ");
  shop mShop = getM();
  FILE *shopDataFile;
  openDbFile(&shopDataFile, shopsData);
  unsigned long shopAddress = getAddressByKey(mShop.id - 1, shopsData);

}

// TODO Testing
void updateShopEmployeeId(shop changeShop, int newEmployeeId) {
  changeShop.employeeId = newEmployeeId;
  FILE *shopDataFile;
  openDbFile(&shopDataFile, shopsData);
  unsigned long shopAddress = getAddressByKey(changeShop.id - 1, shopsData);
  fseek(shopDataFile, (long)shopAddress, SEEK_SET);
  fwrite(&changeShop, sizeof(shop), 1, shopDataFile);
  fclose(shopDataFile);
}

// TODO
void updateS() {}