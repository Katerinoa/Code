#include <stdio.h>

void bubble_sort(char* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		
		for (j = 0; j < sz-i-1; j++)
			
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}	
}

int main()
{
	int n;
	scanf("%d", &n);
	char arr[3];
	for(int i = 0; i < n; i++)
	{
		scanf("%s", arr);
		bubble_sort(&arr[0], 3);
		printf("%c %c %c", arr[0], arr[1], arr[2]);
		printf("\n");
	}

	return 0;
}
