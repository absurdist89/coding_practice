#ifndef __NODE__
#define __NODE__

#include <stdbool.h>

typedef struct node {
	int key;
	struct node *left,*right;
} node;

node* newNode(int key);
bool isLeaf(node *n);

typedef node* list;

#endif
