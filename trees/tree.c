#include <stdio.h>
#include <malloc.h>
#include "tree.h"

static int findLastBitSet(int count)
{
	int ret = -1;
	unsigned int i = 0;
	do
	{
		ret = ((1 << i) & count) ? i:ret;
		i++;
	}
	while(i < sizeof(unsigned int)*8);
	return ret;
}

static void insertNodePriv(tree t, int key, unsigned int count, unsigned int bitmask)
{
	if(bitmask == 1)
	{
		if(bitmask & count)
			t->right = newNode(key);
		else
			t->left = newNode(key);
		return;
	}
	if(bitmask & count)
		insertNodePriv(t->right, key, count, bitmask >> 1);
	else
		insertNodePriv(t->left, key, count, bitmask >> 1);
}

node *newNode(int key)
{
	node *n = (node *)malloc(sizeof(node));
	n->key = key;
	n->left = n->right = NULL;
	return n;
}

bool isLeaf(node *n)
{
	if(!n)
		printf("%s: argument n cannot be NULL!!!\n",
				__func__);
	if((n->left == NULL) &&
		(n->right == NULL))
		return true;
	return false;
}

void inorderTraversal(tree t)
{
	if(t->left)
		inorderTraversal(t->left);
	printf("%d\n",t->key);
	if(t->right)
		inorderTraversal(t->right);
}

node *searchKey(tree t, int key)
{
	if(!t)
		printf("%s: argument t cannot be NULL!!!\n",
				__func__);
	if(t->key == key)
		return t;
	if(t->left)
		return searchKey(t->left, key);
	if(t->right)
		return searchKey(t->right, key);
	return NULL;
}

void insertNode(tree t, int key, unsigned int count)
{
	if(count == 0)
	{
		printf("%s: count cannot be zero!!!\n",
				__func__);
		return;
	}
	unsigned int lbit = findLastBitSet(count);
	insertNodePriv(t, key, count, (1 << (lbit-1)));
}

void deleteNode(tree t)
{
	free(t);
}

node *searchKeyBst(tree t, int key)
{
	if(!t)
		return NULL;
	if(t->key == key)
		return t;
	if(t->key < key)
		return searchKey(t->right, key);
	if(t->key > key)
		return searchKey(t->left, key);
}

void insertNodeBst(tree t, int key)
{
	if(t->key > key)
	{
		if(!t->left)
			t->left = newNode(key);
		else
			insertNodeBst(t->left, key);
	}
	if(t->key < key)
	{
		if(!t->right)
			t->right = newNode(key);
		else
			insertNodeBst(t->right, key);
	}
}

void deleteKeyBst(tree t, int key)
{
	printf("%s: Not implemented\n",
			__func__);
}

typedef struct queue_cellrec {
	node *n; // pointer to node
	struct queue_cellrec *next; // pointer to next cell
} queue_cellrec;
typedef queue_cellrec* queue_cell;

// Level order node queue
typedef struct loqueuerec {
	queue_cell head;
	queue_cell tail;
} loqueuerec;
typedef loqueuerec* loqueue;

static loqueue newQueue()
{
	loqueue lq = (loqueue)malloc(sizeof(loqueuerec));
	lq->head = lq->tail = NULL;
	return lq;
}

static queue_cell newQueueCell(node *n)
{
	queue_cell qcell = (queue_cell)malloc(sizeof(queue_cellrec));
	qcell->n = n;
	qcell->next = NULL;
	return qcell;
}

static bool isQueueEmpty(loqueue q)
{
	if(q->head == NULL)
		return true;
	return false;
}

static void enqueue(loqueue q, node *n)
{
	if(isQueueEmpty(q))
	{
		q->head = q->tail = newQueueCell(n);
		return;
	}
	q->tail->next = newQueueCell(n);
	q->tail = q->tail->next;
}

static node *dequeue(loqueue q)
{
	node *retnode = NULL;
	queue_cell temp = NULL;
	if(isQueueEmpty(q))
		return NULL;
	retnode = q->head->n;
	temp = q->head;
	q->head = q->head->next;
	if(isQueueEmpty(q)) // Check for emptiness
		q->tail = NULL;
	free(temp);
	return retnode;
}

void levelorderTraversal(tree t)
{
	loqueue q = newQueue();
	node *currnode = NULL;
	enqueue(q, t);
	do
	{
		currnode = dequeue(q);
		printf("%d\n",currnode->key);
		if(currnode->left)
			enqueue(q,currnode->left);
		if(currnode->right)
			enqueue(q,currnode->right);
	}
	while(!isQueueEmpty(q));
}
