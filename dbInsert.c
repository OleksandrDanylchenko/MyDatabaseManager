#include <stdlib.h>
#pragma pack(1)
#include "dbInsert.h"

void insertM() {
    if (!validateRecordsAmount(shopsIndices))
        return;

    shop newShop = getNewShopRecord();
    FILE *outputFile = NULL;
    openDbFile(&outputFile, shopsData);
    fseek(outputFile, 0L, SEEK_END);
    fwrite(&newShop, sizeof(shop), 1, outputFile);
    fclose(outputFile);

    keyIndex newShopIndex = getNewDataIndex(shopsData);
    int recordNum = newShopIndex.key + 1;
    openDbFile(&outputFile, shopsIndices);
    fwrite(&recordNum, sizeof(int), 1, outputFile);
    fseek(outputFile, 0L, SEEK_END);
    fwrite(&newShopIndex, sizeof(keyIndex), 1, outputFile);
    fclose(outputFile);
}

shop getNewShopRecord() {
    shop newShop;
    newShop.id = getRecordsAmount(shopsData) + 1;
    printf("New address: ");
    fflush(stdin);
    gets(newShop.address);
    newShop.isActive = true;
    return newShop;
}

// TODO
void insertS() {
    if (!validateRecordsAmount(employeesIndices))
        return;
}

bool validateRecordsAmount(dbFiles fileType) {
    const char *fileNames[] = {"Shops.fl", "Shops.ind", "Employees.fl"};
    if (getRecordsAmount(fileType) >= MAX_AMOUNT) {
        fprintf(stderr, "\n%s cannot store more than 20 records!\n", fileNames[fileType]);
        return false;
    }
    return true;
}



keyIndex getNewDataIndex(dbFiles fileType) {
    keyIndex newShopIndex = {
        .key = getRecordsAmount(fileType),
        .address = getRecordsAmount(fileType) * sizeof(shop)
    };
    return newShopIndex;
}