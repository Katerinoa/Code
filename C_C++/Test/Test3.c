#include <stdio.h>
double getGPA(int grade)
{
	if(grade>=90)
		return 4.0;
	else if(grade>=85)
		return 3.7;
	else if(grade>= 81)
		return 3.3;
	else if(grade >= 78)
		return 3.0;
	else if(grade >= 75)
		return 2.7;
	else if(grade >= 72)
		return 2.3;
	else if(grade >= 68)
		return 2.0;
	else if(grade >= 64)
		return 1.7;
	else if(grade >= 60)
		return 1.0;
	else
		return 0;
}
int main()
{
	double grade, credit, creditSum = 0, GPASum = 0;
	int N;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%lf%lf", &grade, &credit);
		creditSum += credit;
		GPASum += getGPA(grade)*credit;
	}
	printf("%.4lf", GPASum / creditSum);
	return 0;
}