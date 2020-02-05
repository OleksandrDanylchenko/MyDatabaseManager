#pragma pack(1)
#include "dbDeletion.h"
#include "dbRead.h"
#include "dbUpdate.h"

// TODO
void delM() {
  shop delShop = getM();
  if (delShop.isActive) {
    trashZoneData trashZone = getTrashZoneData();
    if (delShop.employeeId != -1) {
      markShopEmployeesInactive(&trashZone, delShop);
    }
    markShopInactive(delShop);
  }
}

// TODO Testing
void markShopEmployeesInactive(trashZoneData *trashZone, shop delShop) {
  employee delEmployee = getEmployeeByKey(delShop.employeeId);
  while (true) {
    trashZone->employees[delEmployee.id] = true;
    markEmployeeInactive(delEmployee);
    if (delEmployee.colleagueId == -1)
      break;
  }
}

// TODO
void delS() {}
