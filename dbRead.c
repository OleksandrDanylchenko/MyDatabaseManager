#include <stdbool.h>
#include <stdlib.h>

#pragma pack(1)

#include "dbFilesHandler.h"
#include "dbRead.h"
#include "dbStructures.h"

shop getM() {
  int userKey = getKeyFromUser();
  shop foundedShop = getShopByKey(userKey);
  if (!foundedShop.isActive)
    fprintf(stderr, "\nCannot find record in Shop.fl\n");
  else
    printf("\n/   Founded shop:\t/\n"
           "/   Id: %d\t\t/\n"
           "/   Address: %s\t/\n"
           "/   EmployeeId: %d\t/\n\n",
           foundedShop.id, foundedShop.address, foundedShop.employeeId);
  return foundedShop;
}

// TODO
void getS() {}

// TODO
void getAll() {}

int getKeyFromUser() {
  int key;
  printf("*\tEnter key of shop: ");
  fflush(stdin);
  scanf("%d", &key);
  return key;
}

shop getShopByKey(int userKey) {
  shop foundedShop = {.isActive = false};
  unsigned long offset = getAddressByKey(userKey, shopsData);
  if (offset != -1) {
    FILE *shopDataFile;
    openDbFile(&shopDataFile, shopsData);
    fseek(shopDataFile, (long)offset, SEEK_SET);
    fread(&foundedShop, sizeof(shop), 1, shopDataFile);
    fclose(shopDataFile);
  }
  return foundedShop;
}

unsigned long getAddressByKey(int userKey, dbFiles fileType) {
  unsigned long address = -1;
  int recordsNum = getRecordsAmount(fileType);
  if (userKey - 1 < recordsNum) {
    keyIndex indices[recordsNum];
    readIndices(indices, recordsNum, fileType);

    for (int i = 0; i < recordsNum; ++i)
      if (indices[i].key == userKey - 1)
        address = indices[i].address;
  }
  return address;
}

void readIndices(keyIndex *indices, int size, dbFiles fileType) {
  FILE *indicesFile = NULL;
  if (fileType == shopsData || fileType == shopsIndices)
    openDbFile(&indicesFile, shopsIndices);
  else
    openDbFile(&indicesFile, employeesIndices);

  fseek(indicesFile, sizeof(int), SEEK_SET);
  fread(indices, sizeof(keyIndex), size, indicesFile);
}