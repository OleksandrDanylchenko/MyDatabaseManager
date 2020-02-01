#ifndef DATABASES_DBSTRUCTURES_H
#define DATABASES_DBSTRUCTURES_H

typedef struct tag_shop {
    int id;
    char *address;
} tShop;

typedef struct tag_employees {
    int id;
    int shopId;
    char *post;
    char *FirstName;
    char *LastName;
} tEmployees;

#endif //DATABASES_DBSTRUCTURES_H