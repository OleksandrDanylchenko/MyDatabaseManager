#include "filesHandler.h"

void openShopsDataFile(FILE **file) {
    char *shopDataPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.fl";
    openFile(file, shopDataPath);
}

void openShopsIndicesFile(FILE **file) {
    char *shopIndicesPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.ind";
    openFile(file, shopIndicesPath);
}

void openEmployeesDataFile(FILE **file) {
    char *employeeDataPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.fl";
    openFile(file, employeeDataPath);
}

void openEmployeesIndicesFile(FILE **file) {
    char *employeeIndicesPath = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.ind";
    openFile(file, employeeIndicesPath);
}

void openFile(FILE **file, char* path) {
    *file = fopen(path, "r+");
}