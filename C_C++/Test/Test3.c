#include<stdio.h>

int main(void)
{
	int a, b, c;
	int m, n;
	int index;
	int res[20] = {0};
	while(scanf("%d %d", &m, &n) != EOF)
	{
		index = 0;
		for(int i = m; i <= n; ++i)
		{
			a = i % 10, b = (i / 10) % 10, c = i / 100;
			if(i == a*a*a + b*b*b + c*c*c)
				res[++index] = i;
		}
		if(!index)
			printf("no\n");
		else
			for(int i = 1; i <= index ;i++)
				printf("%d%c", res[i], " \n"[i == index]);
	}
	return 0;
}
