#include "Node.h"

void NodeSetParent(Node *n, Node *p) 
{  
    n->parent = p; 
} 
 
void NodeSetPrevious(Node *n, Node *p) 
{   
    n->pre = p;  
}  
  
void NodeSetNext(Node *n, Node *p)  
{    
    n->next = p;  
}   
   
void NodeSetData(Node *n, void *data)
{   
    n->data = data; 
}   
   
Node *NodeGetParent(Node *n)
{   
    return n->parent;
}   
   
Node *NodeGetPrevious(Node *n)
{   
    return n->pre;
}
  
Node *NodeGetNext(Node *n)
{  
    return n->next;
}
 
void *NodeGetData(Node *n)
{ 
    return n->data;
}
