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
    fseek(outputFile, 0L, SEEK_END);
    fwrite(&newShopIndex, sizeof(keyIndex), 1, outputFile);
    fclose(outputFile);
}

// TODO
void insertS() {
    if (!validateRecordsAmount(employeesIndices))
        return;
}

bool validateRecordsAmount(dbFiles fileType) {
    const char *fileNames[] = {"Shops.fl", "Shops.ind", "Employees.fl", "Employees.ind"};
    if (getRecordsAmount(fileType) >= MAX_AMOUNT) {
        fprintf(stderr, "\n%s cannot store more than 20 records!\n", fileNames[fileType]);
        return false;
    }
    return true;
}

shop getNewShopRecord() {
    shop newShop;
    newShop.id = getRecordsAmount(shopsData) + 1;
    newShop.isActive = true;
    printf("New address: ");
    newShop.address = calloc(150, sizeof(char));
    fflush(stdin);
    gets(newShop.address);
    return newShop;
}

keyIndex getNewShopIndex() {
    keyIndex newShopIndex = {
            .key = getRecordsAmount(shopsData) + 1,
            .address = sizeof(int) + (getRecordsAmount(shopsData) + 1) * sizeof(shop)
    };
    return newShopIndex;
}