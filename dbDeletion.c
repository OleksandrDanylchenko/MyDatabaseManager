#pragma pack(1)
#include "dbDeletion.h"
#include "dbRead.h"
#include "dbUpdate.h"

// TODO Testing
void delM() {
  shop delShop = getM();
  if (delShop.isActive) {
    trashZone trashZone = getTrashZoneData();
    if (delShop.employeeId != -1)
      writeShopEmployeesInactive(&trashZone, delShop);
    updateShopToInactive(delShop);
    trashZone.shops[delShop.id - 1] = true;
    updateTrashZone(trashZone);
  }
}

// TODO Testing
void writeShopEmployeesInactive(trashZone *trashZone, shop delShop) {
  employee delEmployee = getEmployeeByKey(delShop.employeeId);
  while (true) {
    trashZone->employees[delEmployee.id - 1] = true;
    updateEmployeeToInactive(delEmployee);
    if (delEmployee.colleagueId == -1)
      break;
  }
}

// TODO
void delS() {
  //employee delEmployee =
}

