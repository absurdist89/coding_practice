#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct node {
	int key;
	struct node *next;
	struct node *prev;
} node;

typedef node* list;

typedef struct {
	list head;
	list tail;
	bool invert;
} deque_rec;

typedef deque_rec* deque;

node* new_node(int val)
{
	node *ret = (node *) malloc(sizeof(node));
	ret->key = val;
	ret->next = ret->prev = NULL;
	return ret;
}

deque new_deque(void)
{
	deque ret = (deque) malloc(sizeof(deque_rec));
	ret->head = ret->tail = NULL;
	ret->invert = false;
	return ret;
}

bool deque_empty(deque d)
{
	if (!d) {
		printf("Null args to %s\n",__func__);
		return true;
	}
	return (d->head == NULL) && (d->tail == NULL);
}

void deque_insert(deque d, int val)
{
	node *temp = NULL;

	if (!d) {
		printf("Null args to %s\n",__func__);
		return;
	}

	if (deque_empty(d)) {
		temp = new_node(val);
		d->head = d->tail = temp;
		return;
	}
	
	temp = new_node(val);
	if (d->invert) {
		temp->next = d->head;
		d->head->prev = temp;
		d->head = temp;
	} else {
		temp->prev = d->tail;
		d->tail->next = temp;
		d->tail = temp;
	}
}

void deque_invert(deque d)
{
	if (!d) {
		printf("Null args to %s\n",__func__);
		return;
	}
	d->invert = true;
}

int deque_pop(deque d)
{
	int ret = 0;
	list temp = NULL;

	if (!d) {
		printf("Null args to %s\n",__func__);
		return;
	}

	if (!d->head && !d->tail) {
		printf("%s: cannot pop from an empty deque\n", __func__);
		return -1;
	}

	if (d->head == d->tail) {
		ret = d->head->key;
		free(d->head);
		d->head = NULL;
		d->tail = NULL;
		return ret;
	}

	if (d->invert) {
		ret = d->tail->key;
		temp = d->tail->prev;
		free(d->tail);
		d->tail = temp;
	} else {
		ret = d->head->key;
		temp = d->head->next;
		free(d->head);
		d->head = temp;

	}

	return ret;
}

int main(void)
{
	int i = 0;
	deque d = new_deque();
	for (i = 0; i < 10; i++)
		deque_insert(d, i);
	for (i = 0; i < 5; i++)
		printf("popped %d\n",deque_pop(d));
	deque_invert(d);
	printf("inverted deque\n");
	for (i = 0; i < 5; i++)
		printf("popped %d\n",deque_pop(d));
}






	
