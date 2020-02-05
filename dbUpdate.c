#pragma pack(1)
#include "dbFilesHandler.h"
#include "dbRead.h"
#include "dbStructures.h"
#include <stdio.h>

void updateM() {
  shop updShop = getM();
  if (updShop.isActive) {
    printf("\\\\ Enter new address: ");
    fflush(stdin);
    gets(updShop.address);

    // TODO Fix doubling
    FILE *shopDataFile;
    openDbFile(&shopDataFile, shopsData);
    unsigned long shopAddress = getAddressByKey(updShop.id, shopsData);
    fseek(shopDataFile, (long)shopAddress, SEEK_SET);
    fwrite(&updShop, sizeof(shop), 1, shopDataFile);
    fclose(shopDataFile);
  }
}

void updateShopEmployeeId(shop changeShop, int newEmployeeId) {
  changeShop.employeeId = newEmployeeId;

  // TODO Fix doubling
  FILE *shopsDataFile;
  openDbFile(&shopsDataFile, shopsData);
  unsigned long shopAddress = getAddressByKey(changeShop.id, shopsData);
  fseek(shopsDataFile, (long)shopAddress, SEEK_SET);
  fwrite(&changeShop, sizeof(shop), 1, shopsDataFile);
  fclose(shopsDataFile);
}

void updateS() {
  employee updEmployee = getS();
  if (updEmployee.isActive) {
    printf("\\\\ Enter new first name: ");
    fflush(stdin);
    gets(updEmployee.firstName);

    printf("\\\\ Enter new last name: ");
    fflush(stdin);
    gets(updEmployee.lastName);

    // TODO Fix doubling
    FILE *employeesDataFile = NULL;
    openDbFile(&employeesDataFile, employeesData);
    unsigned long employeeAddress =
        getAddressByKey(updEmployee.id, employeesData);
    fseek(employeesDataFile, (long)employeeAddress, SEEK_SET);
    fwrite(&updEmployee, sizeof(shop), 1, employeesDataFile);
    fclose(employeesDataFile);
  }
}

void updateShopToInactive(shop delShop) {
  delShop.isActive = false;

  // TODO Fix doubling
  FILE *shopDataFile = NULL;
  openDbFile(&shopDataFile, shopsData);
  unsigned long shopAddress = getAddressByKey(delShop.id, shopsData);
  fseek(shopDataFile, (long)shopAddress, SEEK_SET);
  fwrite(&delShop, sizeof(shop), 1, shopDataFile);
  fclose(shopDataFile);
}

void updateEmployeeToInactive(employee delEmployee) {
  delEmployee.isActive = false;

  // TODO Fix doubling
  FILE *employeeDataFile = NULL;
  openDbFile(&employeeDataFile, employeesData);
  unsigned long employeeAddress = getAddressByKey(delEmployee.id, shopsData);
  fseek(employeeDataFile, (long)employeeAddress, SEEK_SET);
  fwrite(&delEmployee, sizeof(employee), 1, employeeDataFile);
  fclose(employeeDataFile);
}

void updateTrashZone(trashZone updTrashZone) {
  FILE *trashZoneFile = NULL;
  openDbFile(&trashZoneFile, trashZoneData);
  fwrite(&updTrashZone, sizeof(trashZoneData), 1, trashZoneFile);
  fclose(trashZoneFile);
}