#ifndef __TREE__
#define __TREE__

#include <stdbool.h>
#include "node.h"

typedef node* tree;

void inorderTraversal(tree t);
node *searchKey(tree t, int key);
void insertNode(tree t, int key, unsigned int count);
void deleteNode(tree t);
node *searchKeyBst(tree t, int key);
void insertNodeBst(tree t, int key);
void deleteKeyBst(tree t, int key);
void levelorderTraversal(tree t);

#endif
