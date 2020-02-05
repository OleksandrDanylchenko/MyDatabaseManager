#include "dbFilesHandler.h"

void openDbFile(FILE **file, dbFiles fileType) {
  char *path = NULL;
  if (fileType == shopsData)
    path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.fl";
  else if (fileType == shopsIndices)
    path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Shops.ind";
  else if (fileType == employeesData)
    path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.fl";
  else if (fileType == employeesIndices)
    path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\Employees.ind";
  else
      path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\trashKeys.tr";
  *file = fopen(path, "r+");
}

int getRecordsAmount(dbFiles fileType) {
  FILE *indicesFile = NULL;
  if (fileType == shopsData || fileType == shopsIndices)
    openDbFile(&indicesFile, shopsIndices);
  else if(fileType == employeesData || fileType == employeesIndices)
    openDbFile(&indicesFile, employeesIndices);
  else
      openDbFile(&indicesFile, trashKeys);

  int amount = 0;
  fread(&amount, sizeof(int), 1, indicesFile);
  fclose(indicesFile);
  return amount;
}