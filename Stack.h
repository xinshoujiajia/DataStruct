#ifndef STACK_H
#define STACK_H

#include "LinkList.h"

typedef LinkList Stack;

#define StackCreate(l, size) (LinkListCreate(l, size))
#define StackTop(l) (LinkListFront(l))
#define StackLength(l) (LinkListLength(l))
#define StackIsEmpty(l) (LinkListIsEmpty(l))
#define StackSize(l) (LinkListSize(l))
#define StackDestory(l) (LinkListDestory(l))
#define StackPush(l, data) (LinkListInsertTail(l, data))
#define StackPop(l) (LinkListRemoveTail(l))

#endif
