#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct _LinkList _LinkList;
typedef _LinkList *LinkList;
struct _LinkList
{
    Node *head;
    size_t length;
    size_t size;
};

void LinkListCreate(LinkList *l, size_t size);
void LinkListClear(LinkList l);
Node *LinkListGetNode(LinkList l, size_t index);
void LinkListInsertNode(LinkList l, Node *p, void *data);
void *LinkListRemoveNode(LinkList l, Node *p);
#define LinkListFor(p, s, e) for (Node *p = s; p != e; p = p->next)
#define LinkListForRe(p, s, e) for (Node *p = s; p != e; p = p->prev)
#define LinkListHead(l) (l->head)
#define LinkListFront(l) (l->head->next)
#define LinkListTail(l) (l->head->prev)
#define LinkListLength(l) (l->length)
#define LinkListIsEmpty(l) (l->length == 0)
#define LinkListSize(l) (l->size)
#define LinkListDestory(l) (LinkListClear(l), free(l->head), free(l), l = NULL)
#define LinkListInsertFront(l, data) (LinkListInsertNode(l, l->head, data))
#define LinkListInsertTail(l, data) (LinkListInsertNode(l, l->head->prev, data))
#define LinkListInsertAt(l, i, data) (LinkListInsertNode(l, LinkListGetNode(l, i), data))
#define LinkListRemoveFront(l) (LinkListRemoveNode(l, l->head))
#define LinkListRemoveTail(l) (LinkListRemoveNode(l, l->head->prev))
#define LinkListRemoveAt(l, i) (LinkListRemoveNode(l, LinkListGetNode(l, i)))
#define LinkListEraserFront(l) (free(LinkListRemoveNode(l, l->head)))
#define LinkListEraserTail(l) (free(LinkListRemoveNode(l, l->head->prev)))
#define LinkListEraserAt(l, i) (free(LinkListRemoveNode(l, LinkListGetNode(l, i))))

#endif
