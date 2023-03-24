#ifndef LINKLIST_H
#define LINKLIST_H

#include <stddef.h>
#include "Node.h"

#define LinkListFor(p,q) for(Node *p = q; NodeGetParent(p); p = NodeGetNext(p))
#define LinkListForReverse(p,q) for(Node *p = q; NodeGetParent(p); p = NodeGetPrevious(p))


typedef struct LinkListHeader LinkListHeader;
typedef Node *LinkList;


struct LinkListHeader
{
    size_t length;
	size_t size;
    void *info;
};

void LinkListSetHeaderInfo(LinkList l, void *info, size_t size);
void *LinkListGetHeaderInfo(LinkList l);

size_t LinkListGetLength(LinkList l);
size_t LinkListGetSize(LinkList l);
int LinkListIsEmpty(LinkList l);

Node *LinkListGetNode(LinkList l, size_t index);
Node *LinkListGetFront(LinkList l);
Node *LinkListGetTail(LinkList l);

void LinkListCreate(LinkList *l, size_t size);
void LinkListCreateFromArray(LinkList *l, void *array, size_t num, size_t size);

void LinkListInsertFront(LinkList l, void *data);
void LinkListInsertTail(LinkList l, void *data);
void LinkListInsert(LinkList l, size_t i, void *data);

void *LinkListRemoveFront(LinkList l);
void *LinkListRemoveTail(LinkList l);
void *LinkListRemove(LinkList l, size_t i);

void LinkListEraseFront(LinkList l);
void LinkListEraseTail(LinkList l);
void LinkListErase(LinkList l, size_t i);

void *LinkListGetData(LinkList l, size_t i);
void *LinkListGetDataFront(LinkList l);
void *LinkListGetDataTail(LinkList l);

void LinkListSetData(LinkList l, size_t i, void *data);
void LinkListSetDataFront(LinkList l, void *data);
void LinkListSetDataTail(LinkList l, void *data);

#endif
