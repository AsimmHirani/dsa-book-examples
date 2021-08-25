//
// Created by Asimm on 2021-08-22.
//

#include "cdap.h"

#include <stdlib.h>

void * CDA_malloc( size_t size ) {
    void* rval = malloc( size );
    if (rval == NULL)
        abort(); // Kill program if we get a null malloc
    return rval;
}

void CDA_free(void *mem) {
    if (mem != NULL) {
        free(mem);
    }
}

char * CDA_new_str(char const * str) {
    unsigned int len = strlen( (str) ) + 1;
    char * dest = (char *)CDA_malloc( len );
    strcpy_s( dest,len,(str));
    return dest;
}