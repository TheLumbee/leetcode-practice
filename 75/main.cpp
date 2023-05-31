#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

class Solution
{
public:
	// https://leetcode.com/problems/sort-colors/description/
	void sortColors(std::vector<int>& nums)
	{
		if (nums.size() == 1)
		{
			return;
		}

		// Three pointers are placed on nums.
		int low = 0, mid = 0, high = nums.size() - 1;

		// 0's should be at low, 1's between low and high, 2's at high.
		while (mid <= high)
		{
			if (!nums[mid])
			{
				Swap(nums[low], nums[mid]);
				mid++;
				low++;
			}

			else if (nums[mid] == 1)
			{
				mid++;
			}

			else
			{
				Swap(nums[mid], nums[high]);
				high--;
			}
		}
	}
};

int main()
{
	// Example 1: Expected (0,0,1,1,2,2)
	std::vector<int> nums{2,0,2,1,1,0};
	Solution().sortColors(nums);
	for (int ii = 0; ii < nums.size(); ii++)
	{
		std::cout << nums[ii] << ' ';
	}

	std::cout << std::endl;

	// Example 2: Expected(0,1,2)
	nums = {2,0,1};
	Solution().sortColors(nums);
	for (int ii = 0; ii < nums.size(); ii++)
	{
		std::cout << nums[ii] << ' ';
	}

	std::cout << std::endl;
	return 0;
}