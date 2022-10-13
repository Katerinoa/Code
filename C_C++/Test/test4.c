#include <stdio.h>
#include <math.h>

int main()
{
    double x;//储存输入
    scanf("%lf", &x);//从键盘读取输入存入x
    double f = exp(2 * x) + sin(pow(x,3.5)) + log(x) - 1;//计算公式的值存在f里
    printf("%.6lf\n", f);//输出f的值
    return 0;
}