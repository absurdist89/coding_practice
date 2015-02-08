#include <stdio.h>
#include <malloc.h>

int cSort(int *a, int size, int max)
{
	int *b = (int *)malloc(sizeof(int)*size
int main()
{
	int *input = NULL;
	int n = 0, i = 0;
	scanf("%d", &n);
	input = (int *) malloc(sizeof(int)*n);
	for(i = 0; i < n; i++)
		scanf("%d", &input[i]);
	radixSort(input);

	free(input);
	return 0;
}

