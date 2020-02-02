#include "dbInsert.h"

// TODO
void insertM() {
    if (!validateRecordsAmount(shopsIndices))
        return;
    shop newShop = getNewShop();

    FILE *outputFile = NULL;
    openDbFile(&outputFile, shopsData);
    fwrite(&newShop, sizeof(shop), 1, outputFile);
    fclose(outputFile);

    int newRecordNumber = getRecordsAmount();
    openDbFile(&outputFile, shopsIndices);

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

shop getNewShop() {
    shop newShop;
    newShop.id = getRecordsAmount(shopsIndices) + 1;
    printf("New address: ");
    newShop.address = calloc(150, sizeof(char));
    gets(newShop.address);
    return newShop;
}

void insertInIndicesFile(dbFiles fileType) {

}