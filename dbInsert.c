#include <stdlib.h>
#include "dbInsert.h"

// TODO
void insertM() {
    if (!validateRecordsAmount(shopsIndices))
        return;
    shop newShop = getNewShopRecord();

    FILE *outputFile = NULL;
    openDbFile(&outputFile, shopsData);
    fwrite(&newShop, sizeof(shop), 1, outputFile);
    free(newShop.address);
    fclose(outputFile);

    keyIndex newShopIndex = getNewShopIndex();
    openDbFile(&outputFile, shopsIndices);
    fwrite(&newShopIndex.key, sizeof(int), 1, outputFile);
    fseek(outputFile, (long) newShopIndex.address, SEEK_SET);
    fwrite(&newShopIndex, sizeof(keyIndex), 1, outputFile);
}

// TODO
void insertS() {
    if (!validateRecordsAmount(employeesIndices))
        return;
}

bool validateRecordsAmount(dbFiles fileType) {
    if (getRecordsAmount(fileType) >= 20) {
        fprintf(stderr, "%s cannot store more than 20 records!", fileNames[fileType]);
        return false;
    }
    return true;
}

shop getNewShopRecord() {
    shop newShop;
    newShop.id = getRecordsAmount(shopsData) + 1;
    printf("New address: ");
    newShop.address = calloc(150, sizeof(char));
    gets(newShop.address);
    return newShop;
}

keyIndex getNewShopIndex() {
    keyIndex newShopIndex = {
            .key = getRecordsAmount(shopsData) + 1,
            .address = (getRecordsAmount(shopsData) + 1) * sizeof(shop)
    };
    return newShopIndex;
}

void insertInIndicesFile(dbFiles fileType) {

}