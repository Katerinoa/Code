#include <stdio.h>
int main()
{
    int zheng = 0, fu = 0, ling = 0, n = 0, shu = 0, i;
    while (1)
    {
        scanf("%d", &n);
        if (!n)
        {
            return 0;
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &shu);
            if (shu > 0)
            {
                zheng++;
            }
            else if (shu == 0)
            {
                ling++;
            }
            else
            {
                fu++;
            }
        }
        printf("%d %d %d\n", zheng, ling, fu);
        zheng = 0;
        fu = 0;
        ling = 0;
    }
}
