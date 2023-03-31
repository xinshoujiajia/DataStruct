#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
struct Node
{
    void *data;
    Node *prev;
    Node *next;
};
#define NodeData(n) (n->data)
#define NodePrev(n) (n->prev)
#define NodeNext(n) (n->next)

#endif
