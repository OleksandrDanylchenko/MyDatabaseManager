#pragma pack(1)
#include "dbDeletion.h"
#include "dbRead.h"
#include "dbUpdate.h"

// TODO
void delM() {
  shop delShop = getM();
  if (delShop.isActive) {
    trashZoneData trashZone = getTrashZoneData();
    if (delShop.employeeId != -1)
      writeShopEmployeesInactive(&trashZone, delShop);
    writeShopInactive(delShop);
  }
}

// TODO Testing
void writeShopEmployeesInactive(trashZoneData *trashZone, shop delShop) {
  employee delEmployee = getEmployeeByKey(delShop.employeeId);
  while (true) {
    trashZone->employees[delEmployee.id] = true;
    writeEmployeeInactive(delEmployee);
    if (delEmployee.colleagueId == -1)
      break;
  }
}

// TODO
void delS() {}
