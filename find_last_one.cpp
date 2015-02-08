#include <iostream>
using namespace std;

int find_last_one(char *a, int lo, int hi)
{
	int mid = (hi-lo)/2 + lo;
	if (hi == lo)	return a[lo] ? lo : 0;
	if (a[mid] && !a[mid +1])
		return mid;
	if (!a[mid] && a[mid - 1])
		return mid - 1;
	if (a[mid])	return find_last_one(a, mid + 1, hi);
	return find_last_one(a, lo, mid - 1);
}
/*
int find_rank(int *a, int lo, int hi, int key)
{
	int mid = (hi - lo)/2 + lo;

	if (a[mid] == key)	return mid;
	if (hi == lo) {
		if (key < a[lo])	return lo;
		if (key > a[lo])	return lo + 1;
	}

	if (a[mid] < key)
		return find_rank(a, mid + 1, hi, key);
	return find_rank(a, lo, mid - 1, key);
}
*/

int get_first_occurrence(int *a, int lo, int hi, int key)
{
	int mid = (hi - lo)/2 + lo;

	if (a[mid] == key) {
		if (mid - 1 < 0)
			return mid;
		if (a[mid - 1] < key)
			return mid;
		return get_first_occurrence(a, lo, mid - 1, key);
	}
	if (hi == lo) {
		if (key < a[lo])	return lo;
		if (key > a[lo])	return lo + 1;
	}

	if (a[mid] < key)
		return get_first_occurrence(a, mid + 1, hi, key);
	return get_first_occurrence(a, lo, mid - 1, key);
}

int main(void)
{
//	char arr[] = {1, 1, 1, 1 };
//	cout << find_last_one(arr, 0, sizeof(arr)/sizeof(char) - 1)  + 1 << "\n";
	int arr[] = {'a', 'a', 'a', 'a', 'a', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 's', 's', 't', 'u', 'y'};
//	cout << find_rank(arr, 0, sizeof(arr)/sizeof(int) - 1, '\0')  << "\n";
	cout << get_first_occurrence(arr, 0, sizeof(arr)/sizeof(int) - 1, 'r')  << "\n";
}

