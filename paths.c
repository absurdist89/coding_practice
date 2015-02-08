#include <stdio.h>

int main()
{
	int a[1000][1000];
	int i, j, m, n;
	scanf("%d",&m);
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
		a[m][i] = 1;
	for(i = m-1; i > 0; i--)
	{
		a[i][n] = 1;
		for(j = n-1; j > 0; j--)
			a[i][j] = a[i+1][j] + a[i][j+1];
	}
	printf("%d\n",a[1][1]);
	return 0;
}

