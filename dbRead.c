#include <stdbool.h>
#include <stdlib.h>

#pragma pack(1)

#include "dbFilesHandler.h"
#include "dbRead.h"
#include "dbStructures.h"

shop getM() {
  int userKey = getUserKey(shopsData);
  shop foundedShop = getShopByKey(userKey);
  if (!foundedShop.isActive)
    fprintf(stderr, "\n*** Cannot find record in Shop.fl! ***\n");
  else
    formatShopOutput(foundedShop);
  return foundedShop;
}

employee getS() {
  shop mShop = getM();
  employee foundedEmployee = {.isActive = false};
  if (mShop.isActive) {
    if (mShop.employeeId == -1)
      fprintf(stderr, "\n*** Shop on %s doesn't have any employee! ***\n",
              mShop.address);
    else {
      int userKey = getUserKey(employeesData);
      employee employee = getEmployeeByKey(mShop.employeeId);
      bool isFounded = false;
      while (true)
        if (employee.id == userKey && employee.isActive) {
          isFounded = true;
          break;
        } else if (employee.colleagueId == -1)
          break;
        else
          employee = getEmployeeByKey(employee.colleagueId);
      if (!isFounded)
        fprintf(
            stderr,
            "\n*** Shop on %s doesn't have employee with ID number %d! ***\n",
            mShop.address, userKey);
      else {
        formatEmployeeOutput(employee);
        foundedEmployee = employee;
      }
    }
  }
  return foundedEmployee;
}

void getAll() {
  FILE *outputFile = NULL;
  openDbFile(&outputFile, shopsData);
  shop outShop = {.isActive = false};
  while (true) {
    fread(&outShop, sizeof(shop), 1, outputFile);
    if (feof(outputFile))
      break;
    if (outShop.isActive)
      formatShopOutput(outShop);
  }
  fclose(outputFile);

  openDbFile(&outputFile, employeesData);
  employee outEmployee = {.isActive = false};
  while (true) {
    fread(&outEmployee, sizeof(employee), 1, outputFile);
    if (feof(outputFile))
      break;
    formatEmployeeOutput(outEmployee);
  }
  fclose(outputFile);
}

void formatShopOutput(shop outShop) {
  printf("\n\n/   Founded shop:\t/\n"
         "/   Id: %d\t\t/\n"
         "/   Address: %s\t/\n"
         "/   EmployeeId: %d\t/\n\n",
         outShop.id, outShop.address, outShop.employeeId);
}

void formatEmployeeOutput(employee outEmployee) {
  printf("\n\n/   Founded employee:\t/\n"
         "/   Id: %d\t\t/\n"
         "/   First name: %s\t/\n"
         "/   Last name: %s\t/\n"
         "/   ColleagueId: %d\t/\n\n",
         outEmployee.id, outEmployee.firstName, outEmployee.lastName,
         outEmployee.colleagueId);
}

int getUserKey(dbFiles fileType) {
  int key;
  if (fileType == shopsData || fileType == shopsIndices)
    printf("*\tEnter key of shop: ");
  else
    printf("*\tEnter key of employee: ");
  fflush(stdin);
  scanf("%d", &key); // NOLINT(cert-err34-c)
  return key;
}

shop getShopByKey(int userKey) {
  shop foundedShop = {.isActive = false};
  // TODO Work with copy
  unsigned long offset = getAddressByKey(userKey, shopsData);
  if (offset != -1) {
    FILE *shopDataFile;
    openDbFile(&shopDataFile, shopsData);
    fseek(shopDataFile, (long)offset, SEEK_SET);
    fread(&foundedShop, sizeof(shop), 1, shopDataFile);
    fclose(shopDataFile);
  }
  return foundedShop;
}

employee getEmployeeByKey(int userKey) {
  employee foundedEmployee = {.isActive = false};
  // TODO Work with copy
  unsigned long offset = getAddressByKey(userKey, employeesData);
  if (offset != -1) {
    FILE *employeeDataFile;
    openDbFile(&employeeDataFile, employeesData);
    fseek(employeeDataFile, (long)offset, SEEK_SET);
    fread(&foundedEmployee, sizeof(employee), 1, employeeDataFile);
    fclose(employeeDataFile);
  }
  return foundedEmployee;
}

unsigned long getAddressByKey(int key, dbFiles fileType) {
  unsigned long address = -1;
  int recordsNum = getRecordsNum(fileType);
  if (key - 1 < recordsNum) {
    keyIndex indices[recordsNum];
    readIndices(indices, recordsNum, fileType);

    for (int i = 0; i < recordsNum; ++i)
      if (indices[i].key == key - 1)
        address = indices[i].address;
  }
  return address;
}

void readIndices(keyIndex *indices, int size, dbFiles fileType) {
  FILE *indicesFile = NULL;
  if (fileType == shopsData || fileType == shopsIndices)
    openDbFile(&indicesFile, shopsIndices);
  else
    openDbFile(&indicesFile, employeesIndices);

  fseek(indicesFile, sizeof(int), SEEK_SET);
  fread(indices, sizeof(keyIndex), size, indicesFile);
  fclose(indicesFile);
}

int getRecordsNum(dbFiles fileType) {
  FILE *indicesFile = NULL;
  if (fileType == shopsData || fileType == shopsIndices)
    openDbFile(&indicesFile, shopsIndices);
  else if (fileType == employeesData || fileType == employeesIndices)
    openDbFile(&indicesFile, employeesIndices);

  int num = 0;
  fread(&num, sizeof(int), 1, indicesFile);
  fclose(indicesFile);
  return num;
}

trashZoneData getTrashZoneData() {
  trashZone trashZone;

  FILE *trashZoneFile = NULL;
  fread(&trashZone, sizeof(trashZone), 1, trashZoneFile);
  fclose(trashZoneFile);

  if (trashZone.shopsAmount == 0)
    for (int i = 0; i < MAX_RECORDS_AMOUNT; ++i)
      trashZone.shops[i] = false;
  if (trashZone.employeesAmount == 0)
    for (int j = 0; j < MAX_RECORDS_AMOUNT; ++j)
      trashZone.employees[j] = false;

  return trashZone;
}