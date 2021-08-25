//
// Created by Asimm on 2021-08-22.
//

#ifndef DSA_BOOK_CDA_H
#define DSA_BOOK_CDA_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*------------- DEFINE STATEMENTS ----------------*/

#define CDA_TRUE                (1)
#define CDA_FALSE               (0)

#define CDA_ASSERT(  exp  )     (assert(  (exp)  ))
#define CDA_CARD(  arr  )       (sizeof((arr))/sizeof(*(arr)))
#define CDA_NEW(  type  )       ((type*)CDA_malloc(  sizeof(type)  ))
#define CDA_NEW_STR(  str  )    (CDA_new_str( str ))
#define CDA_NEW_STR_IF(  str  ) ((str) == NULL ? NULL: CDA_NEW_STR((str)))

/*------------- TYPE STATEMENTS ----------------*/

typedef signed char         CDA_INT8_t;
typedef unsigned char       CDA_UINT8_t;

typedef signed short        CDA_INT16_t;
typedef unsigned short      CDA_UINT16_t;

typedef signed int          CDA_INT32_t;
typedef unsigned int        CDA_UINT32_t;

typedef signed int         CDA_BOOL_t;
/*------------- FUNCTION PROTOTYPES ----------------*/

void *CDA_malloc            ( size_t size );
void CDA_free               ( void *mem );
char * CDA_new_str          (char const * str);

#endif //DSA_BOOK_CDA_H
