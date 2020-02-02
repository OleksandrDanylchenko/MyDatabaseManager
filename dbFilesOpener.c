#include "dbFilesOpener.h"

void openDbFile(FILE **file, dbFiles dbFileType) {
    char *path = NULL;
    if (dbFileType == ShopsData)
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.fl";
    else if (dbFileType == ShopsIndices)
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.ind";
    else if (dbFileType == EmployeesData)
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.fl";
    else
        path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.ind";
    *file = fopen(path, "r+");
}