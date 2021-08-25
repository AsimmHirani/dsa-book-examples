#include <stdio.h>

#include "cda/cda.h"

int main(void) {
    int* myarr = CDA_malloc(sizeof(int)*500);
    printf("Hello, World!\n");
    CDA_free(myarr);
    return 0;
}
