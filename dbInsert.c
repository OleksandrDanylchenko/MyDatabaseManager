#include <stdio.h>
#include "dbInsert.h"
#include "dbFilesHandler.h"

// TODO
void insertM() {

}

// TODO
void insertS() {

}

void validateRecordsAmount(dbFiles fileType) {
    if(getIndicesAmount(fileType) >= 20) {
        fprintf(stderr, "%s cannot store more than 20 records!", fileNames[fileType]);
        return;
    }
}