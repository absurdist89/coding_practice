#include <stdio.h>
#include <malloc.h>
#include "node.h"

node *newNode(int key)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

list insertNodeSinglyLinked(list l, int key)
{
	node *temp = NULL;
	if(l == NULL)
	{
		l = newNode(key);
		return l;
	}
	temp = l;
	while(temp->right)	
		temp = temp->right;
	temp->right = newNode(key);
	return l;
}

void printList(list l)
{
	node *temp;
	if(!l)
		return;
	temp = l;
	while(temp)
	{
		printf("%d ",temp->key);
		temp = temp->right;
	}
	printf("\n");
}

