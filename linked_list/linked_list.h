//
// Created by Asimm on 2021-08-22.
//

#ifndef DSA_BOOK_LINKED_LIST_H
#define DSA_BOOK_LINKED_LIST_H

#include "cda/cdap.h"

typedef struct enq_item_s {
    struct enq_item_s *flink;
    struct enq_item_s *blink;
    char* name;
} ENQ_ITEM_t;

typedef ENQ_ITEM_t ENQ_ANCHOR_t;

ENQ_ANCHOR_t * ENQ_new_list         (char const * name);
ENQ_ITEM_t * ENQ_new_item           (char const * name, size_t size);
CDA_BOOL_t ENQ_is_item_enqed        (ENQ_ITEM_t const * item);
CDA_BOOL_t ENQ_is_empty             (ENQ_ANCHOR_t const * list);
ENQ_ITEM_t * ENQ_add_head           (ENQ_ANCHOR_t * list, ENQ_ITEM_t * item);
ENQ_ITEM_t * ENQ_add_tail           (ENQ_ANCHOR_t * list, ENQ_ITEM_t * item);
ENQ_ITEM_t * ENQ_add_before         (ENQ_ITEM_t * item, ENQ_ITEM_t * before);
ENQ_ITEM_t * ENQ_add_after          (ENQ_ITEM_t * item, ENQ_ITEM_t * after);
ENQ_ITEM_t * ENQ_deq_item           (ENQ_ITEM_t * item);
ENQ_ITEM_t * ENQ_deq_head           (ENQ_ANCHOR_t * list);
ENQ_ITEM_t * ENQ_deq_tail           (ENQ_ANCHOR_t * list);
ENQ_ITEM_t * ENQ_destroy_item       (ENQ_ITEM_t * item );
ENQ_ANCHOR_t * ENQ_empty_list       (ENQ_ANCHOR_t * list);
ENQ_ANCHOR_t * ENQ_destroy_list     (ENQ_ANCHOR_t * list);

#define ENQ_GET_HEAD ( list ) ((list)->flink)
#define ENQ_GET_TAIL ( list ) ((list)->blink)
#define ENQ_GET_NEXT ( item ) ((item)->flink)
#define ENQ_GET_PREV ( list ) ((item)->blink)
#define ENQ_GET_LIST_NAME ( list ) ((list)->name)
#define ENQ_GET_ITEM_NAME ( item ) ((item)->name)

#endif //DSA_BOOK_LINKED_LIST_H
