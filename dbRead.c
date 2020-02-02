#include <stdlib.h>
#include <stdbool.h>
#include "dbRead.h"
#include "dbStructures.h"
#include "dbFilesHandler.h"

// TODO
void getM() {
    int recordsNum = getRecordsAmount(shopsData);
    keyIndex indices[recordsNum];
    if (!readIndices(indices, recordsNum))
        return;

    int userKey = getKeyFromUser(shopsData);
    shop foundedShop = getShopByKey(indices, userKey);
    if (!foundedShop.isActive) {
        fprintf(stderr, "\nCannot find record in Shop.fl\n");
        return;
    }
    printf("Id: %d \n Address: %s", foundedShop.id, foundedShop.address);
}

// TODO
void getS() {

}

// TODO
void getAll() {

}

int getKeyFromUser(dbFiles fileType) {
    int key;
    printf("Enter key of shop: ");
    fflush(stdin);
    scanf("%d", &key);
    return key;
}

bool readIndices(keyIndex indices[], int size) {
    FILE *shopIndicesFile = NULL;
    openDbFile(&shopIndicesFile, shopsIndices);
    unsigned int readKeysNum = fread(indices, sizeof(keyIndex), MAX_AMOUNT, shopIndicesFile);
    fclose(shopIndicesFile);
    if (size != readKeysNum) {
        fprintf(stderr, "\nCannot properly read all Shop.fl records!\n");
        return false;
    }
    return true;
}

shop getShopByKey(keyIndex indices[], int userKey) {
    unsigned long offset = indices[userKey].address + sizeof(int);

    FILE *shopDataFile;
    openDbFile(&shopDataFile, shopsData);
    fseek(shopDataFile, (long) offset, SEEK_SET);

    shop foundedShop;
    fread(&foundedShop, sizeof(shop), 1, shopDataFile);
    return foundedShop;
}