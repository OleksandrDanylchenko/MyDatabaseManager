#include "dbFilesHandler.h"

void openDbFile(FILE **file, dbFiles fileType) {
    char *path = NULL;
    if (fileType == shopsData)
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.fl";
    else if (fileType == shopsIndices)
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.ind";
    else if (fileType == employeesData)
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.fl";
    else
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.ind";
    *file = fopen(path, "r+");
}

int getIndicesAmount(dbFiles fileType) {
    FILE *indicesFile = NULL;
    openDbFile(&indicesFile, fileType);
    int amount = 0;
    fread(&amount, sizeof(int), 1, indicesFile);
    fclose(indicesFile);
    return amount;
}