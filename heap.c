#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct {
	int heap_size;
	int arr_length;
	int a[1000000];
} heap;

#define LEFT(i)   ((i << 1) + 1)
#define RIGHT(i)  ((i << 1) + 2)
#define PARENT(i) ((i % 2) ? (i >> 1) : ((i >> 1) - 1))

void swap_array(int *a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int max_three(int a, int b, int c)
{
	return (a < b) ? ((b < c) ? c : b) : ((a < c) ? c : a);
}

void heapify(heap *A, int i)
{
	int left = 0, right = 0;
	int *a = A->a;
	if(LEFT(i) < A->heap_size)
		left = a[LEFT(i)];
	if(RIGHT(i) < A->heap_size)
		right = a[RIGHT(i)];
	// Find the largest of a[i], left and right
	if(max_three(left, right, a[i]) == a[i])
		return; // Subtree from i is already a heap
	if(max_three(left, right, a[i]) == left)
	{
		swap_array(a, LEFT(i), i);
		heapify(A, LEFT(i));
	}
	if(max_three(left, right, a[i]) == right)
	{
		swap_array(a, RIGHT(i), i);
		heapify(A, RIGHT(i));
	}
}

heap *build_max_heap(int *arr, size_t arr_size_in_bytes)
{
	int i = 0;
	heap *h = (heap *)malloc(sizeof(heap));
	memcpy(h->a, arr, arr_size_in_bytes);
	h->heap_size = (arr_size_in_bytes)/sizeof(int);
	for(i = PARENT(h->heap_size - 1); i >= 0; i--)
		heapify(h, i);
	return h;
}

void print_heap(heap *h)
{
	int i = 0;
	printf("Heap Size = %d\n",h->heap_size);
	for(i = 0; i < h->heap_size; i++)
		printf("%d ", h->a[i]);
	printf("\n");
}

int main()
{
	int num_keys;
	int arr[1000000];
	int i = 0;
	scanf("%d",&num_keys);
	for(i = 0; i < num_keys; i++)
		scanf("%d",&arr[i]);

	heap *h = build_max_heap(arr, sizeof(int) * num_keys);
	print_heap(h);
}

