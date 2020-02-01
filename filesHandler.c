#include "filesHandler.h"

void openShopsDataFile(FILE *file) {
    char *shopDataPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.fl";
    fopen(shopDataPath, "w+");
}

void openShopsIndicesFile(FILE *file) {
    char *shopIndicesPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.ind";
    fopen(shopIndicesPath, "w+");
}

void openEmployeesDataFile(FILE *file) {
    char *shopDataPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.fl";
    fopen(shopDataPath, "w+");
}

void openEmployeesIndicesFile(FILE *file) {
    char *employeeIndicesPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.ind";
    fopen(employeeIndicesPath, "w+");
}