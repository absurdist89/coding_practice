#include <stdio.h>
#include "node.h"

void insertMiddle(node *n1, node *n2, node* n3)
{
	n1->right = n3;
	n3->right = n2;
}

void mergeAlternate(list *l1, list *l2)
{
	node *temp2 = *l2, *it2 = *l2;
	node *temp1 = *l1, *it1 = *l1;
	if(!(*l1))
		return;
	while(temp2)
	{
		if(!it1->right)
		{
			*l2 = temp2;
			break;
		}
		it2 = temp2->right;
		it1 = temp1->right;
		insertMiddle(temp1, temp1->right, temp2);
		temp2 = it2;
		temp1 = it1;
	}
}

int main()
{
	list l1 = NULL, l2 = NULL;
	int i = 0;
	for(i=0;i<10;i++)
		l1 = insertNodeSinglyLinked(l1,i);
	printList(l1);

	for(;i<20;i++)
		l2 = insertNodeSinglyLinked(l2,i);
	printList(l2);
	
	mergeAlternate(&l1, &l2);
	printList(l1);
	printList(l2);
}

