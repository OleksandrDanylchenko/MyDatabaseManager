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

int getRecordsNum(dbFiles fileType) {
  FILE *indicesFile = NULL;
  if (fileType == shopsData || fileType == shopsIndices)
    openDbFile(&indicesFile, shopsIndices);
  else if(fileType == employeesData || fileType == employeesIndices)
    openDbFile(&indicesFile, employeesIndices);

  int num = 0;
  fread(&num, sizeof(int), 1, indicesFile);
  fclose(indicesFile);
  return num;
}