#include <iostream>
using namespace std;

int main()
{
	int n, num, c, select;
	n = 0;
	num = 0;
	cin >> n;
	cin >> select; //这时题目中的x
	for (int i = 0; i < n; i++)
	{
		int b = i + 1;
		do
		{
			c = b % 10;
			b /= 10;
			if (c == select)
			{
				num++;
			}
		} while (b != 0);
	}
	cout << num << endl;

	return 0;
}