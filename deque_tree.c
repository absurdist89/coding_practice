#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct tnode {
	int key;
	struct tnode *left;
	struct tnode *right;
} tnode;

typedef tnode* tree;

typedef struct lnode {
	tree t;
	struct lnode *next;
	struct lnode *prev;
} lnode;

typedef lnode* list;

typedef struct {
	list head;
	list tail;
	bool invert;
} deque_rec;

typedef deque_rec* deque;

lnode* new_lnode(tree t)
{
	lnode *ret = (lnode *) malloc(sizeof(lnode));
	ret->t = t;
	ret->next = ret->prev = NULL;
	return ret;
}

tnode* new_tnode(int key)
{
	tnode *ret = (tnode *) malloc(sizeof(tnode));
	ret->key = key;
	ret->left = ret->right = NULL;
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
	return ((d->head == NULL) && (d->tail == NULL));
}

void deque_insert(deque d, tree t)
{
	lnode *temp = NULL;

	if (!d) {
		printf("Null args to %s\n",__func__);
		return;
	}

	if (deque_empty(d)) {
		temp = new_lnode(t);
		d->head = d->tail = temp;
		return;
	}
	
	temp = new_lnode(t);
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
	d->invert = !(d->invert);
}

tree deque_pop(deque d)
{
	tree ret = 0;
	list temp = NULL;

	if (!d) {
		printf("Null args to %s\n",__func__);
		return;
	}

	if (!d->head && !d->tail) {
		printf("%s: cannot pop from an empty deque\n", __func__);
		return NULL;
	}

	if (d->head == d->tail) {
		ret = d->head->t;
		free(d->head);
		d->head = NULL;
		d->tail = NULL;
		return ret;
	}

	if (d->invert) {
		ret = d->tail->t;
		temp = d->tail->prev;
		free(d->tail);
		d->tail = temp;
	} else {
		ret = d->head->t;
		temp = d->head->next;
		free(d->head);
		d->head = temp;
	}

	return ret;
}

void spiral_level_order(tree t)
{
	deque q = NULL;
	if (!t)
		return;
	q = new_deque();
	deque_insert(q, t);
	deque_insert(q, NULL);
	bool invert = false;
	tree temp = NULL;
	do {
		temp = deque_pop(q);
		if (temp) {
			printf("%d ", temp->key);
			if (invert) {
				if (temp->right)
					deque_insert(q, temp->right);
				if (temp->left)
					deque_insert(q, temp->left);
			} else {
				if (temp->left)
					deque_insert(q, temp->left);
				if (temp->right)
					deque_insert(q, temp->right);
			}
		} else {
			invert = !invert;
			deque_invert(q);
			deque_insert(q, NULL);
			printf("\n");
		}

		if (q->head->t == NULL &&
				q->tail->t == NULL) {
			printf("\n");
			break;
		}

	} while(!deque_empty(q));

	free(q);
}

int main(void)
{
	tree root = new_tnode(0);

	root->left = new_tnode(1);
	root->right = new_tnode(2);
	root->left->left = new_tnode(3);
	root->left->right = new_tnode(4);
	root->right->left = new_tnode(5);
	root->right->right = new_tnode(6);

	tree root2 = new_tnode(0);

	root2->left = new_tnode(1);
	root2->right = new_tnode(2);
	root2->left->left = new_tnode(3);
	root2->left->right = new_tnode(4);
	root2->right->left = new_tnode(5);
	root2->right->right = new_tnode(6);

	root->right->right->left = root2;

	spiral_level_order(root);

}






	
