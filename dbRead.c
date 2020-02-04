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
    printf("\n\n/   Founded shop:\t/\n"
           "/   Id: %d\t\t/\n"
           "/   Address: %s\t/\n"
           "/   EmployeeId: %d\t/\n\n",
           foundedShop.id, foundedShop.address, foundedShop.employeeId);
  return foundedShop;
}

// TODO Testing
void getS() {
  shop mShop = getM();
  if (!mShop.isActive || mShop.employeeId == -1)
    fprintf(stderr, "\n*** Shop on %s doesn't have any employee! ***\n",
            mShop.address);
  else {
    int userKey = getUserKey(employeesData);
    employee employee = getEmployeeByKey(mShop.employeeId);
    bool isFounded = false;
    while (true)
      if (employee.id == userKey) {
        isFounded = true;
        break;
      } else if (employee.colleagueId == -1)
        break;
      else
        employee = getEmployeeByKey(employee.colleagueId);
    if (!isFounded)
      fprintf(stderr, "\n*** Shop on %s doesn't have employee with %d ID number! ***\n",
              mShop.address, userKey);
    else
      printf("\n\n/   Founded employee:\t/\n"
             "/   Id: %d\t\t/\n"
             "/   First name: %s\t/\n"
             "/   Last name: %s\t/\n"
             "/   ColleagueId: %d\t/\n\n",
             employee.id, employee.firstName, employee.lastName, employee.colleagueId);
  }
}

// TODO
void getAll() {}

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

unsigned long getAddressByKey(int userKey, dbFiles fileType) {
  unsigned long address = -1;
  int recordsNum = getRecordsAmount(fileType);
  if (userKey - 1 < recordsNum) {
    keyIndex indices[recordsNum];
    readIndices(indices, recordsNum, fileType);

    for (int i = 0; i < recordsNum; ++i)
      if (indices[i].key == userKey - 1)
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