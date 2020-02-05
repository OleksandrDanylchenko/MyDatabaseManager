#pragma pack(1)
#include "dbDeletion.h"
#include "dbRead.h"
#include "dbUpdate.h"

void delM() {
  shop delShop = getM();
  if (delShop.isActive) {
    trashZone trashZone = getTrashZoneData();
    if (delShop.employeeId != -1)
      writeShopEmployeesInactive(&trashZone, delShop);
    delShop.isActive = false;
    updateShop(delShop);
    ++trashZone.shopsAmount;
    trashZone.shops[delShop.id - 1] = true;
    updateTrashZone(trashZone);
  }
}

void writeShopEmployeesInactive(trashZone *trashZone, shop delShop) {
  employee delEmployee = getEmployeeByKey(delShop.employeeId);
  while (true) {
    ++trashZone->employeesAmount;
    trashZone->employees[delEmployee.id - 1] = true;
    delEmployee.isActive = false;
    updateEmployee(delEmployee);
    if (delEmployee.nextColleagueId == -1)
      break;
  }
}

// TODO Testing
void delS() {
  employee delEmployee = getS();
  delEmployee.isActive = false;
  updateEmployee(delEmployee);
  if (delEmployee.prevColleagueId == -1 && delEmployee.nextColleagueId != -1) {
    shop mShop = getShopByKey(delEmployee.shopId);
    mShop.employeeId = delEmployee.nextColleagueId;
    updateShop(mShop);
  } else if (delEmployee.prevColleagueId != -1 && delEmployee.nextColleagueId != -1) {
    employee prevColleague = getEmployeeByKey(delEmployee.prevColleagueId);
    employee nextColleague = getEmployeeByKey(delEmployee.nextColleagueId);
    prevColleague.nextColleagueId = nextColleague.id;
    updateEmployee(prevColleague);
  }
}