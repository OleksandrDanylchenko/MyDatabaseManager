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
      path = "D:\\Studying\\2_Course\\DataBases\\LaboratoryWork1\\trashZone.tr";
  *file = fopen(path, "r+");
}