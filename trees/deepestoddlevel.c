#include <stdio.h>
#include "tree.h"

int max(int a, int b)
{
	return (a >= b)?a:b;
}

int deepestoddlevel(tree t, int level)
{
	int ld = 0, rd = 0;
	if(isLeaf(t))
	{
		if(level%2)
			return level;
		return 0;
	}
	if(t->left)
		ld = deepestoddlevel(t->left, level + 1);
	if(t->right)
		rd = deepestoddlevel(t->right, level + 1);
	return max(ld, rd);
}

int main()
{
/*
	tree t = newNode(1);
	t->left = newNode(2);
	t->right = newNode(3);
	t->left->left = newNode(4);
	t->right->left = newNode(5);
	t->right->right = newNode(6);
	t->right->left->right = newNode(7);
	t->right->left->right->left = newNode(9);
	t->right->right->right = newNode(8);
	t->right->right->right->right = newNode(10);
	t->right->right->right->right->left = newNode(11);
*/
	tree t = newNode(1);
	t->left = newNode(2);
	t->left->right = newNode(9);
	printf("%d\n",deepestoddlevel(t, 1));
}
