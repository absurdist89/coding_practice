#include <stdio.h>
#include "tree.h"
#include <stdbool.h>

int altSum(tree t, bool isNegative)
{
	int rsum = 0, lsum = 0;
	if(!t)
		return 0;
	if(t->left)
		lsum = altSum(t->left, !isNegative);
	if(t->right)
		rsum = altSum(t->right, !isNegative);
	return ((isNegative)?-1:1)*t->key + lsum + rsum;
}

int main()
{
	tree t = newNode(50);
	insertNodeBst(t, 12);
	insertNodeBst(t, 13);
	insertNodeBst(t, 95);
	insertNodeBst(t, 44);
	insertNodeBst(t, 23);
	insertNodeBst(t, 25);
	levelorderTraversal(t);
	printf("%d\n",altSum(t, false));
}
