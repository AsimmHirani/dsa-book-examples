//
// Created by Asimm on 2021-08-22.
//

#include "linked_list.h"

#include "../cdap.h"

ENQ_ANCHOR_t * ENQ_new_list(char const * name) {
    ENQ_ANCHOR_t * rval = CDA_NEW(ENQ_ANCHOR_t);
    rval->blink = rval;
    rval->flink = rval;
    rval->name = CDA_NEW_STR_IF(name); // Remember to delete this when cleaning up

    return rval;
}

ENQ_ITEM_t * ENQ_new_item(char const * name, size_t size) {
    CDA_ASSERT(size >= sizeof(ENQ_ITEM_t));
    ENQ_ITEM_t * rval = (ENQ_ITEM_t *) CDA_malloc(size);
    rval->blink = rval;
    rval->flink = rval;
    rval->name = CDA_NEW_STR_IF(name);
    return rval;
}

CDA_BOOL_t ENQ_is_item_enqed( ENQ_ITEM_t const * const item ) {
    return item->flink == item ? CDA_FALSE : CDA_TRUE;
}

CDA_BOOL_t ENQ_is_empty(ENQ_ANCHOR_t const * const list) {
    return list->flink == list ? CDA_TRUE : CDA_FALSE;
}

ENQ_ITEM_t* ENQ_add_head(ENQ_ANCHOR_t * list, ENQ_ITEM_t * item) {
    CDA_ASSERT(ENQ_is_item_enqed(item) == CDA_FALSE);
    item->blink = list; // The item is now pointing to the list
    item->flink = list->flink; // Copy the existing "next-link" to item
    list->flink->blink = item; // if the list is empty, list->blink will be list, so list->blink will be item
    list->flink = item; // Write the item to the head of the list
    return item;
}

ENQ_ITEM_t* ENQ_add_tail(ENQ_ANCHOR_t * list, ENQ_ITEM_t * item) {
    CDA_ASSERT(ENQ_is_item_enqed(item) == CDA_FALSE);
    item->flink = list; // The item is now pointing to the list
    item->blink = list->blink; // Copy the existing "back-link" to item
    list->blink->flink = item;
    list->blink = item; // Write the item to the tail of the list
    return item;
}

ENQ_ITEM_t * ENQ_add_before (ENQ_ITEM_t * item, ENQ_ITEM_t * before) {
    CDA_ASSERT(ENQ_is_item_enqed(item) == CDA_FALSE);
    item->flink = before;
    item->blink = before->blink;
    before->blink->flink = item;
    before->blink = item;
    return item;
}

ENQ_ITEM_t * ENQ_add_after (ENQ_ITEM_t * item, ENQ_ITEM_t * after) {
    CDA_ASSERT(ENQ_is_item_enqed(item) == CDA_FALSE);
    item->flink = after->flink;
    item->blink = after;
    after->flink->blink = item;
    after->flink = item;
    return item;
}

ENQ_ITEM_t * ENQ_deq_item(ENQ_ITEM_t * item) {
    item->flink->blink = item->blink;
    item->blink->flink = item->flink;
    item->flink = item;
    item->blink = item;
    return item;
}

ENQ_ITEM_t * ENQ_deq_head( ENQ_ANCHOR_t * list ) {
    return (ENQ_is_empty(list) == CDA_TRUE) ? list : ENQ_deq_item(list->flink);
}

ENQ_ITEM_t * ENQ_deq_tail( ENQ_ANCHOR_t * list ) {
    return (ENQ_is_empty(list) == CDA_TRUE) ? list : ENQ_deq_item(list->blink);
}

ENQ_ITEM_t * ENQ_destroy_item( ENQ_ITEM_t * item ) {
    ENQ_deq_item(item);
    CDA_free(item->name);
    CDA_free(item);
    return NULL;
}

ENQ_ANCHOR_t * ENQ_empty_list( ENQ_ANCHOR_t * list ) {
    while (!ENQ_is_empty(list))
        ENQ_destroy_item(list->flink);
    return list;
}

ENQ_ANCHOR_t * ENQ_destroy_list( ENQ_ANCHOR_t * list ) {
    ENQ_empty_list(list);
    CDA_free(list->name);
    CDA_free(list);
    return NULL;
}