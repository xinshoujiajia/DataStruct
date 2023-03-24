#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
struct Node
{
	Node *parent;
    Node *pre;
    Node *next;
    void *data;
};

void NodeSetParent(Node *n, Node *p);
void NodeSetPrevious(Node *n, Node *p);
void NodeSetNext(Node *n, Node *p);
void NodeSetData(Node *n, void *data);

Node *NodeGetParent(Node *n);
Node *NodeGetPrevious(Node *n);
Node *NodeGetNext(Node *n);
void *NodeGetData(Node *n);

#endif
