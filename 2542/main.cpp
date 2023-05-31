#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
public:
	// https://leetcode.com/problems/maximum-subsequence-score/description/
	long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k)
	{
		// If length of nums is 1, just return the value
		if (nums1.size() == 1)
		{
			return nums1[0] * nums2[0];
		}

		// Since minimum of each nums2 of subsequence is needed, store in vector and sort for iteration.
		// Index should be stored with value for nums1 lookup.
		std::vector<std::pair<int, int>> orderedMins(nums2.size(), {0, 0});
		for (int ii = 0; ii < nums2.size(); ii++)
		{
			orderedMins[ii] = {nums2[ii], ii};
		}

		std::sort(orderedMins.begin(), orderedMins.end(), [](const std::pair<int, int>& a,
			const std::pair<int, int>& b) { return a.first > b.first; });

		// Use a priority queue to store values with low priority for easy removal.
		std::priority_queue<int, std::vector<int>, std::greater<int>> values;
		long long sum = 0, result = 0;
		for (auto ii : orderedMins)
		{
			// Keep track of the current sum.
			sum += nums1[ii.second];
			values.push(nums1[ii.second]);

			// Make sure only 'k' values are calculated.
			if (values.size() >= k)
			{
				result = std::max(result, sum * ii.first);
				sum -= values.top();
				values.pop();
			}
		}

		return result;
	}
};

int main()
{
	// Example 1: Expected (12)
	std::vector<int> nums1{1,3,3,2},
		nums2{2,1,3,4};
	std::cout << Solution().maxScore(nums1, nums2, 3) << std::endl;

	// Example 2: Expected (30)
	nums1 = {4,2,3,1,1};
	nums2 = {7,5,10,9,6};
	std::cout << Solution().maxScore(nums1, nums2, 1) << std::endl;
	return 0;
}