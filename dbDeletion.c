#pragma pack(1)
#include "dbDeletion.h"
#include "dbRead.h"
#include "dbUpdate.h"
#include <string.h>

// TODO
void delM() {
  trashZoneData trashZone;
  shop delShop = getM();
  if (delShop.isActive) {
    if (delShop.employeeId != -1) {
      int *inactiveEmployees = markShopEmployeesInactive(delShop);
      memcpy(trashZone.trashEmployeeKeys, inactiveEmployees, MAX_RECORDS_AMOUNT);
    }
    //markShopInactive(delShop);
  }
}

int *markShopEmployeesInactive(shop delShop) {
  static int inactiveEmployees[MAX_RECORDS_AMOUNT];
}

// TODO
void delS() {}


