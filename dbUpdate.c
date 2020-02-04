#pragma pack(1)
#include "dbFilesHandler.h"
#include "dbRead.h"
#include "dbStructures.h"
#include <stdio.h>

void updateM() {
  shop updShop = getM();
  if (updShop.isActive) {
    printf("\\\\ Enter new address: ");
    fflush(stdin);
    gets(updShop.address);

    // TODO Fix doubling
    FILE *shopDataFile;
    openDbFile(&shopDataFile, shopsData);
    unsigned long shopAddress = getAddressByKey(updShop.id, shopsData);
    fseek(shopDataFile, (long)shopAddress, SEEK_SET);
    fwrite(&updShop, sizeof(shop), 1, shopDataFile);
    fclose(shopDataFile);
  }
}

void updateShopEmployeeId(shop changeShop, int newEmployeeId) {
  changeShop.employeeId = newEmployeeId;

  // TODO Fix doubling
  FILE *shopDataFile;
  openDbFile(&shopDataFile, shopsData);
  unsigned long shopAddress = getAddressByKey(changeShop.id, shopsData);
  fseek(shopDataFile, (long)shopAddress, SEEK_SET);
  fwrite(&changeShop, sizeof(shop), 1, shopDataFile);
  fclose(shopDataFile);
}

// TODO
void updateS() {}