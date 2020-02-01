#include <stdio.h>
#include <stdbool.h>
#include "dbReading.h"
#include "dbDeletion.h"

unsigned int getOption();

int main() {
    while (true) {
        unsigned int userOpt = getOption();
        switch (userOpt) {
            case 1: getM();
                break;
            case 2: getS();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
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
        scanf("%d", &opt);
    } while (!(opt >= 1 && opt <= 10));

    return opt;
}