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
  if (!readIndices(indices, recordsNum))
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

bool readIndices(keyIndex *indices, int size) {
  FILE *shopIndicesFile = NULL;
  openDbFile(&shopIndicesFile, shopsIndices);

  fseek(shopIndicesFile, sizeof(int), SEEK_SET);
  unsigned int readKeysNum =
      fread(indices, sizeof(keyIndex), MAX_AMOUNT, shopIndicesFile);
  fclose(shopIndicesFile);
  if (size != readKeysNum)
    return false;
  return true;
}

shop getShopByKey(keyIndex indices[], int arrSize, int userKey) {
  shop foundedShop;

  unsigned long offset = -1;
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