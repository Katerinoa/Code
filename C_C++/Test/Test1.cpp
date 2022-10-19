#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
	int p = 0, currentNum = 0xc0c0c0c0, times = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > currentNum)
		{
			currentNum = nums[i];
			times = 1;
		}
		else if (nums[i] == currentNum && times >= 2)
			continue;
		else if (nums[i] == currentNum)
			times++;

		nums[p++] = currentNum;
	}
	return p;
}
int main()
{
	vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4};
	cout << removeDuplicates(nums) << endl;
	for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
		cout << *i;

	return 0;
}