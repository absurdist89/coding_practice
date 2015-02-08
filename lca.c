#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} node;

typedef node* tree;

tree new_node(int key)
{
	tree t = (tree) malloc(sizeof(struct node));
	t->key = key;
	t->left = t->right = NULL;
	return t;
}

void find_lca(tree t, int a, int b, bool *fa, bool *fb, tree *lca)
{
	if (!t)	return;

	bool a_already_found = *fa, b_already_found = *fb;
	bool a_found_in_self = false, b_found_in_self = false;

	if (a_already_found && b_already_found)	return;

//	printf("at node %d: %d %s, %d %s\n",t->key, a, a_already_found ? "already found" : "not found",
//			b, b_already_found ? "already found" : "not found");
	if (t->key == a) {
		if (a == b) {
			*lca = t;
			*fa = true;
			*fb = true;
			return;
		}
		a_found_in_self = true;
		*fa = true;
//		printf("found %d\n", a);
	} else if (t->key == b) {
		b_found_in_self = true;
		*fb = true;
//		printf("found %d\n", b);
	}
	find_lca(t->left, a, b, fa, fb, lca);
	find_lca(t->right, a, b, fa, fb, lca);
//	printf("finishing node %d: %d %s, %d %s\n",t->key, a, *fa ? "found" : "not found",
//			b, *fb ? "found" : "not found");

	if ((a_found_in_self && !b_already_found && *fb ) ||
	(b_found_in_self && !a_already_found && *fa) ||
	(!a_already_found && !b_already_found && *fa && *fb && !*lca))
	{
//		printf("lca found at node %d\n", t->key);
		*lca = t;
	}
	return;
}

void get_lca(tree t, int a, int b)
{
	bool fa = false;
	bool fb = false;
	tree lca = NULL;
	find_lca(t, a, b, &fa, &fb, &lca);
	if (lca)
		printf("lca of %d and %d = %d\n", a, b, lca->key);
	else
		printf("lca of %d and %d not found\n", a, b);
}

int main(void) {
	tree t = new_node(1);
	t->left = new_node(2);
	t->right = new_node(3);
	t->left->left = new_node(4);
	t->left->right = new_node(5);
	t->right->left = new_node(6);
	t->right->right = new_node(7);

	get_lca(t, 0, 0);
	get_lca(t, 1, 1);
	get_lca(t, 6, 7);
	get_lca(t, 9, 10);


}


