#include <stdio.h>
#include "dbInsert.h"
#include "dbFilesHandler.h"

// TODO
void insertM() {
    if(getIndicesAmount(shopsIndices) >= 20) {
        fprintf(stderr, "ShopData file cannot store more than 20 records!");
        return;
    }

}

// TODO
void insertS() {

}

void validateRecordsAmount(dbFiles fileType) {
    if(getIndicesAmount(fileType) >= 20) {
        fprintf(stderr, "ShopData file cannot store more than 20 records!");
        return;
    }
}