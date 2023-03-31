#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *LinkListGetNode(LinkList l, size_t index)
{
    Node *p = LinkListHead(l);
    if (index > l->length / 2)
    {
        for (size_t i = l->length; i >= index; i--)
        {
            p = p->prev;
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
    LinkList p = (LinkList)malloc(sizeof(_LinkList));
    Node *a = (Node *)malloc(sizeof(Node));
    a->prev = a;
    a->next = a;
    p->head = a;
    p->length = 0;
    p->size = size;
    *l = p;
}

void LinkListClear(LinkList l)
{
    if (l == NULL || LinkListIsEmpty(l))
    {
        return;
    }
    Node *p = l->head->next;
    while (p != l->head)
    {
        free(p->data);
        p = p->next;
        free(p->prev);
    }
    l->head->next = l->head;
    l->head->prev = l->head;
    l->length = 0;
}

void LinkListInsertNode(LinkList l, Node *p, void *data)
{
    Node *a = (Node *)malloc(sizeof(Node));
    a->data = malloc(l->size);
    memcpy(a->data, data, l->size);
    a->prev = p->prev;
    a->next = p;
    p->prev->next = a;
    p->prev = a;
    l->length++;
}

void *LinkListRemoveNode(LinkList l, Node *p)
{
    if (l == NULL || LinkListIsEmpty(l))
    {
        return NULL;
    }
    void *data = p->data;
    p->next->prev = p->prev;
    p->prev->next = p->next;
    free(p);
    l->length--;
    return data;
}
