#include <stdbool.h>
#include <stdlib.h>

#pragma pack(1)

#include "dbFilesHandler.h"
#include "dbRead.h"
#include "dbStructures.h"

shop getM() {
  shop foundedShop = {.isActive = false};
  int recordsNum = getRecordsAmount(shopsData);
  keyIndex indices[recordsNum];
  if (!readIndices(indices, recordsNum, shopsData))
    fprintf(stderr, "\nCannot properly read all Shop.fl records!\n");
  else {
    int userKey = getKeyFromUser(shopsData);
    foundedShop = getShopByKey(indices, recordsNum, userKey);
    if (!foundedShop.isActive)
      fprintf(stderr, "\nCannot find record in Shop.fl\n");
    else
      printf("\nId: %d\nAddress: %s\n\n", foundedShop.id, foundedShop.address);
  }
  return foundedShop;
}

// TODO
void getS() {}

// TODO
void getAll() {}

int getKeyFromUser(dbFiles fileType) {
  int key;
  printf("Enter key of shop: ");
  fflush(stdin);
  scanf("%d", &key);
  return key;
}

shop getShopByKey(keyIndex indices[], int arrSize, int userKey) {
  shop foundedShop;


  for (int i = 0; i < arrSize; ++i)
    if (indices[i].key == userKey)
      offset = indices[i].address;

  if (userKey - 1 >= arrSize || offset == -1) {
    foundedShop.isActive = false;
  } else {
    FILE *shopDataFile;
    openDbFile(&shopDataFile, shopsData);
    fseek(shopDataFile, (long)offset, SEEK_SET);
    fread(&foundedShop, sizeof(shop), 1, shopDataFile);
    fclose(shopDataFile);
  }
  return foundedShop;
}

bool readIndices(keyIndex *indices, int size, dbFiles fileType) {
  FILE *indicesFile = NULL;
  openDbFile(&indicesFile, fileType);

  fseek(indicesFile, sizeof(int), SEEK_SET);
  unsigned int readKeysNum =
      fread(indices, sizeof(keyIndex), MAX_AMOUNT, indicesFile);
  fclose(indicesFile);
  if (size != readKeysNum)
    return false;
  return true;
}

int getAddressByKey(int userKey, dbFiles fileType) {
  unsigned long address = -1;
}