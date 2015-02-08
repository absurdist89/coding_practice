#include <stdio.h>

int searchKey(int *a, int size, int key)
{
	int i = 0;
	for(i=0;i<size;i++)
		if(a[i]==key)
			return i;
	return -1;
}

int *constructPostorder(int *inorder, int *preorder, int size)
{
	int postOder[size];
	int root = preorder[size - 1];
	int rootIndex = searchKey(inorder, size, root);
	printf("%d ",root);
	if(rootIndex == -1)
		return NULL;
	if(rootIndex != 0)
	{
		constructPostorder(inorder,
				preorder,
				rootIndex);
	}
	if(rootIndex != size-1)
	{
		constructPostorder(&inorder[rootIndex + 1],
				&preorder[rootIndex],
				size - rootIndex - 1);
	}
}

int main()
{
	int inorder[] = {12,13,15,16,17,19,31,32,35,36,37};
	int preorder[] = {13,15,12,16,19,17,32,36,37,35,31};
	constructPostorder(inorder, preorder, sizeof(inorder)/sizeof(int));
}

