#include <stdio.h>
#include<string.h>

int main(void)
{
	int N, o;
	int temp;
    scanf("%d", &N);
    // getchar();//Œ¸ ’ªÿ≥µ
    char ch[4];
	for(int x = 0; x < N; ++x)
	{
        memset(ch, 0, sizeof(ch));
        scanf("%s", ch);

		if(ch[0] > ch[1])
		{	
			temp = ch[1];
			ch[2] = ch[3];
			ch[2] = temp;
		}
		if(ch[1] > ch[2])
		{
			temp = ch[2];
			ch[2] = ch[3];
			ch[3] = temp;
			
		}
		if(ch[0] > ch[2])
		{
			temp = ch[1];
			ch[1] = ch[3];
			ch[3] = temp;
			
		}
		printf("%c %c %c", ch[1], ch[2], ch[3]);
		
		printf("\n");
	}
	
	
	return  0;
}
