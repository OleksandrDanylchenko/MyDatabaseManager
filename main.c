#include <stdio.h>
#include <stdbool.h>
#pragma pack(1)
#include "dbRead.h"
#include "dbDeletion.h"
#include "dbUpdate.h"
#include "dbInsert.h"

unsigned int getOption();

int main() {
    while (true) {
        unsigned int userOpt = getOption();
        switch (userOpt) {
            case 1:
                getM();
                break;
            case 2:
                getS();
                break;
            case 3:
                delM();
                break;
            case 4:
                delS();
                break;
            case 5:
                updateM();
                break;
            case 6:
                updateS();
                break;
            case 7:
                insertM();
                break;
            case 8:
                insertS();
                break;
            case 9:
                getAll();
                break;
            case 10:
                return 0;
            default:
                continue;
        }
    }
}

unsigned int getOption() {
    printf("****  Choose option:  ****\n"
           "*\t1. get-m\t * \n"
           "*\t2. get-s\t * \n"
           "*\t3. del-m\t * \n"
           "*\t4. del-s\t * \n"
           "*\t5. update-m\t * \n"
           "*\t6. update-s\t * \n"
           "*\t7. insert-m\t * \n"
           "*\t8. insert-s\t * \n"
           "*\t9. show-all\t * \n"
           "*\t10. exit\t * \n"
           "**************************\n");

    unsigned int opt;
    do {
        printf("*  Opt: ");
        fflush(stdin);
        scanf("%d", &opt);
    } while (!(opt >= 1 && opt <= 10));

    return opt;
}