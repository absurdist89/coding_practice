#include <iostream>
using namespace std;

void swap(char *str, int i, int j)
{
	if (i == j)
		return;
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void reverse(char *str)
{
	int len = 0;
	int i = 0;
	if (!str)
		return;
	while(1) {
		if (!str[i++]) {
			len = i - 1;
			break;
		}
	}
	for (int i = 0, j = len - 1;
			i <= j; i++, j--)
		swap(str, i, j);
}

int main(void) {
	char str[] = "marvelous";
	cout << str << "\n";
	reverse(str);
	cout << str << "\n";
}

