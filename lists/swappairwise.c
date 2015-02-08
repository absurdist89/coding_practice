#include <stdio.h>
#include "node.h"

list swapPairWise(list l)
{
	if(!l)
		return NULL;
	if(!l->right)
		return l;
	node *temp1 = l->right;
	node *temp2 = temp1->right;
	temp1->right = l;
	l->right = swapPairWise(temp2);
	return temp1;
}

int main()
{
	list l = NULL;
	int i = 0;
	for(i=0;i<10;i++)
		l = insertNodeSinglyLinked(l,i);
	printList(l);
	l = swapPairWise(l);
	printList(l);
}
