#include <stdio.h>
#include <malloc.h>
#include <string.h>

void swap(char *a, int i, int j)
{
	char temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return;
}

void reverse(char *a, int len)
{
	int i = 0;
	for (i = 0; i<len/2; i++)
		swap(a, i, len - i - 1);
}

void get_digits(char *s)
{
	printf("enter number:\n");
	scanf("%s", s);
}

void find_next_greater()
{
	char s[200];
	get_digits(s);
	int num_digits = strlen(s);
	printf("num_digits = %d\n", num_digits);
	if (num_digits == 1 || !num_digits) {
		printf("not possible\n");
		return;
	}

	char *digits = s;
	int i = 0; int swap_point = -1;

	for (i = num_digits - 2; i >= 0; i--) {
		if (digits[i] < digits[i+1])
			break;
	}
	swap_point = i;
	printf("swap_point = %d\n",swap_point);
	if (swap_point == -1) {
		printf("not possible\n");
		return;
	}
	int least = swap_point + 1;
	for (i = swap_point + 2; i < num_digits; i++) {
		if ((digits[swap_point] < digits[i]) &&
				(digits[least] > digits[i]))
			least = i;
	}
	printf("least = %d\n", least);
	swap(digits, swap_point, least);
	printf("after swap = %s\n", digits);
	for (i = least; i < num_digits; i++)
		if (digits[i] < digits[i+1])
			swap(digits, i, i+1);
	printf("after swap = %s\n", digits);
	reverse(digits + swap_point + 1, num_digits - swap_point - 1);
	printf("Next greater number = %s\n", digits);
	return;
}

int main(void)
{
	find_next_greater();
	return 0;
}



