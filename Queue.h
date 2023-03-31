#ifndef STACK_H
#define STACK_H

#include "LinkList.h"

typedef LinkList Queue;

#define QueueCreate(l, size) (LinkListCreate(l, size))
#define QueueFront(l) (LinkListFront(l))
#define QueueTail(l) (LinkListTail(l))
#define QueueLength(l) (LinkListLength(l))
#define QueueIsEmpty(l) (LinkListIsEmpty(l))
#define QueueSize(l) (LinkListSize(l))
#define QueueDestory(l) (LinkListDestory(l))
#define QueueEn(l, data) (LinkListInsertTail(l, data))
#define QueueDe(l) (LinkListRemoveFront(l))

#endif
