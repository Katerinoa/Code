#include <stdio.h>
#include <math.h>

int main()
{
    double x;//��������
    scanf("%lf", &x);//�Ӽ��̶�ȡ�������x
    double f = exp(2 * x) + sin(pow(x,3.5)) + log(x) - 1;//���㹫ʽ��ֵ����f��
    printf("%.6lf\n", f);//���f��ֵ
    return 0;
}