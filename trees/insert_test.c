#include <stdio.h>
#include "tree.h"

int main()
{
	tree t = newNode(12);
	int i = 2;
	for(i = 2; i < 10; i++)
		insertNode(t, i, (unsigned int) i);
	inorderTraversal(t);
}
 
