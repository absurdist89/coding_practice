#include <stdio.h>
#include "tree.h"

bool pruneksum(tree t, int ksum, int currsum)
{
	currsum += t->key;
	if(isLeaf(t))
	{
		if((currsum + t->key) < ksum)
		{
			deleteNode(t);
			return true;
		}
	}
	if(t->left && pruneksum(t->left, ksum, currsum))
		t->left = NULL;
	if(t->right && pruneksum(t->right, ksum, currsum))
		t->right = NULL;
	if(isLeaf(t))
	{
		if(currsum < ksum)
		{
			deleteNode(t);
			return true;
		}
	}
	return false;
}

void main(void)
{
	tree t = newNode(12);
	unsigned int i = 2;
	for(i = 2;i<10;i++)
		insertNode(t, ((i%2)?-1:1)*i, i);
	levelorderTraversal(t);
	printf("Pruning\n");
	pruneksum(t,22,0);
	levelorderTraversal(t);
}
