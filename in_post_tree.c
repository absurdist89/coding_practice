#include <stdio.h>

typedef struct node {
	int val;
	struct node *left, *right;
} node;
typedef node* tree;

int g_postindex = 0;

tree new_node(int val)
{
	tree tmp = (tree)malloc(sizeof(node));
	tmp->val = val;
	tmp->left = tmp->right = NULL;
}

int find(int *in, int start, int end, int val)
{
	int i = 0;
	for(i = start; i <= end; i++)
		if(in[i] == val)
			return i;
	return -1;
}

tree create_tree(int *in, int *post,
		int in_start, int in_end)
{
	int root = post[g_postindex];
	if(in_start > in_end)
		return NULL;
	tree tmp = new_node(root);
	int root_ind = find(in, in_start, in_end, root);
	printf("root = %d root_ind = %d in_start = %d in_end = %d\n",
			root, root_ind, in_start, in_end);
	if(root_ind == -1)
	{
		printf("Inorder and postorder do not correspond\n");
		exit(-1);
	}
	g_postindex--;
	tmp->right = create_tree(in, post, root_ind+1, in_end);
	tmp->left = create_tree(in, post, in_start, root_ind-1);
	return tmp;
}

void print_inorder(tree tmp)
{
	if(!tmp)
		return;
	printf("%d ",tmp->val);
	print_inorder(tmp->left);
	print_inorder(tmp->right);
}

int main()
{
	int n;
	scanf("%d",&n);
	g_postindex = n-1;
	int in[100],post[100], i =0;
	for(i=0;i<n;i++)
		scanf("%d", &in[i]);
	for(i = 0;i<n;i++)
		scanf("%d",&post[i]);
	tree tmp = create_tree(in, post, 0, n - 1);
	print_inorder(tmp);
}
