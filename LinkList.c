#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LinkListSetHeaderInfo(LinkList l, void *info, size_t size)
{
    LinkListHeader *h = (LinkListHeader *)l->data;
    h->info = malloc(size);
    memcpy(h->info, info, size);
}

void *LinkListGetHeaderInfo(LinkList l)
{
    return ((LinkListHeader *)l->data)->info;
}

size_t LinkListGetLength(LinkList l)
{
    if (l == NULL)
    {
        return 0;
    }
    return ((LinkListHeader *)l->data)->length;
}

size_t LinkListGetSize(LinkList l)
{
    if (l == NULL)
    {
        return 0;
    }
    return ((LinkListHeader *)l->data)->size;
}

int LinkListIsEmpty(LinkList l)
{
    return LinkListGetLength(l) == 0;
}

Node *LinkListGetNode(LinkList l, size_t index)
{
    if (LinkListIsEmpty(l) || index == 0)
    {
        return NULL;
    }
    if (index > LinkListGetLength(l))
    {
        return NULL;
    }
    Node *p = l;
    if (index > LinkListGetLength(l) / 2)
    {
        for (size_t i = LinkListGetLength(l); i >= index; i--)
        {
            p = p->pre;
        }
    }
    else
    {
        for (size_t i = 0; i < index; i++)
        {
            p = p->next;
        }
    }
    return p;
}

void LinkListCreate(LinkList *l, size_t size)
{
    LinkList a = (LinkList)malloc(sizeof(Node));
    LinkListHeader h;
    a->pre = a;
    a->next = a;
    a->data = malloc(sizeof(LinkListHeader));
    h.length = 0;
    h.size = size;
    h.info = NULL;
    memcpy(a->data, &h, sizeof(h));
    *l = a;
}

void LinkListCreateFromArray(LinkList *l, void *array, size_t num, size_t size)
{
    LinkList a = (LinkList)malloc(sizeof(Node));
    LinkListHeader h;
    Node **A = (Node **)malloc(num * sizeof(Node *));
    char *p = (char *)array;
    A[0] = (Node *)malloc(sizeof(Node));
    A[0]->pre = a;
    A[0]->data = malloc(size);
    memcpy(A[0]->data, p, size);
    p += size;
    for (size_t i = 1, j = 0; i < num; i++, j++)
    {
        A[i] = (Node *)malloc(sizeof(Node));
        A[j]->next = A[i];
        A[i]->pre = A[j];
        A[i]->data = malloc(size);
        memcpy(A[i]->data, p, size);
        p += size;
    }
    A[num - 1]->next = a;
    a->next = A[0];
    a->pre = A[num - 1];
    a->parent = NULL;
    a->data = malloc(sizeof(LinkListHeader));
    h.length = num;
    h.size = size;
    h.info = NULL;
    memcpy(a->data, &h, sizeof(h));
    *l = a;
}

void LinkListInsert(LinkList l, size_t index, void *data)
{
    Node *p = LinkListGetNode(l, index);
    size_t size = LinkListGetSize(l);
    if (p == NULL)
    {
        p = l;
    }
    Node *a = (Node *)malloc(sizeof(Node));
    a->pre = p->pre;
    a->next = p;
    a->parent = l;
    p->pre->next = a;
    p->pre = a;
    a->data = malloc(size);
    memcpy(a->data, data, size);
    ((LinkListHeader *)l->data)->length++;
}

void LinkListInsertFront(LinkList l, void *data)
{
    Node *a = (Node *)malloc(sizeof(Node));
    size_t size = LinkListGetSize(l);
    a->pre = l;
    a->next = l->next;
    a->parent = l;
    l->next->pre = a;
    l->next = a;
    a->data = malloc(size);
    memcpy(a->data, data, size);
    ((LinkListHeader *)l->data)->length++;
}

void LinkListInsertTail(LinkList l, void *data)
{
    Node *a = (Node *)malloc(sizeof(Node));
    size_t size = LinkListGetSize(l);
    a->pre = l->pre;
    a->next = l;
    a->parent = l;
    l->pre->next = a;
    l->pre = a;
    a->data = malloc(size);
    memcpy(a->data, data, size);
    ((LinkListHeader *)l->data)->length++;
}

void *LinkListRemove(LinkList l, size_t index)
{
    Node *p = LinkListGetNode(l, index);
    if (p == NULL)
    {
        return NULL;
    }
    void *data = p->data;
    p->next->pre = p->pre;
    p->pre->next = p->next;
    free(p);
    ((LinkListHeader *)l->data)->length--;
    return data;
}

void *LinkListRemoveFront(LinkList l)
{
    if (LinkListIsEmpty(l))
    {
        return NULL;
    }
    void *data = l->next->data;
    Node *p = l->next->next;
    free(l->next);
    l->next = p;
    p->pre = l;
    free(p);
    ((LinkListHeader *)l->data)->length--;
    return data;
}

void *LinkListRemoveTail(LinkList l)
{
    if (LinkListIsEmpty(l))
    {
        return NULL;
    }
    void *data = l->pre->data;
    Node *p = l->pre->pre;
    free(l->pre);
    l->pre = p;
    p->next = l;
    ((LinkListHeader *)l->data)->length--;
    return data;
}

void LinkListErase(LinkList l, size_t index)
{
    free(LinkListRemove(l, index));
}

void LinkListEraseFront(LinkList l)
{
    free(LinkListRemoveFront(l));
}

void LinkListEraseTail(LinkList l)
{
    free(LinkListRemoveTail(l));
}

Node *LinkListGetFront(LinkList l)
{
    return l->next;
}

Node *LinkListGetTail(LinkList l)
{
    return l->pre;
}

void *LinkListGetData(LinkList l, size_t index)
{
    Node *p = LinkListGetNode(l, index);
    if (p == NULL)
    {
        return NULL;
    }
    return p->data;
}

void *LinkListGetDataFront(LinkList l)
{
    if (LinkListIsEmpty(l))
    {
        return NULL;
    }
    return l->next->data;
}

void *LinkListGetDataTail(LinkList l)
{
    if (LinkListIsEmpty(l))
    {
        return NULL;
    }
    return l->pre->data;
}

void LinkListSetData(LinkList l, size_t index, void *data)
{
    void *p = LinkListGetData(l, index);
    size_t size = LinkListGetSize(l);
    if (p == NULL)
    {
        return;
    }
    memcpy(p, data, size);
}

void LinkListSetDataFront(LinkList l, void *data)
{
    void *p = LinkListGetDataFront(l);
    size_t size = LinkListGetSize(l);
    if (p == NULL)
    {
        return;
    }
    memcpy(p, data, size);
}

void LinkListSetDataTail(LinkList l, void *data)
{
    void *p = LinkListGetDataTail(l);
    size_t size = LinkListGetSize(l);
    if (p == NULL)
    {
        return;
    }
    memcpy(p, data, size);
}
