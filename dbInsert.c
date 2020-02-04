#include <stdlib.h>
#pragma pack(1)
#include "dbInsert.h"
#include "dbRead.h"
#include "dbUpdate.h"

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
  shop newShop = {.id = getRecordsAmount(shopsData) + 1,
                  .employeeId = -1,
                  .isActive = true};
  printf("\\\\ New address: ");
  fflush(stdin);
  gets(newShop.address);
  return newShop;
}

void insertS() {
  if (!validateRecordsAmount(employeesIndices))
    return;
  shop mShop = getM();
  if(mShop.isActive) {
    employee newEmployee = getNewEmployeeRecord(mShop.employeeId);

    FILE *outputFile = NULL;
    openDbFile(&outputFile, employeesData);
    fseek(outputFile, 0L, SEEK_END);
    fwrite(&newEmployee, sizeof(employee), 1, outputFile);
    fclose(outputFile);

    keyIndex newEmployeeIndex = getNewDataIndex(employeesData);
    int recordNum = newEmployeeIndex.key + 1;
    openDbFile(&outputFile, employeesIndices);
    fwrite(&recordNum, sizeof(int), 1, outputFile);
    fseek(outputFile, 0L, SEEK_END);
    fwrite(&newEmployeeIndex, sizeof(keyIndex), 1, outputFile);
    fclose(outputFile);

    updateShopEmployeeId(mShop, newEmployee.id);
  }
}

employee getNewEmployeeRecord(int colleagueId) {
  employee newEmployee = {.id = getRecordsAmount(employeesData) + 1,
                          .isActive = true,
                          .colleagueId = colleagueId};
  printf("\\\\ Enter credentials of new employee:\n"
         "\\\\ First name: ");
  fflush(stdin);
  gets(newEmployee.firstName);
  printf("\\\\ Last name: ");
  fflush(stdin);
  gets(newEmployee.lastName);
  return newEmployee;
}

bool validateRecordsAmount(dbFiles fileType) {
  const char *fileNames[] = {"Shops.fl", "Shops.ind", "Employees.fl",
                             "Employees.ind"};
  if (getRecordsAmount(fileType) >= MAX_RECORDS_AMOUNT) {
    fprintf(stderr, "\n%s cannot store more than 20 records!\n",
            fileNames[fileType]);
    return false;
  }
  return true;
}

keyIndex getNewDataIndex(dbFiles fileType) {
  keyIndex newShopIndex = {.key = getRecordsAmount(fileType),
                           .address =
                               getRecordsAmount(fileType) * sizeof(shop)};
  return newShopIndex;
}