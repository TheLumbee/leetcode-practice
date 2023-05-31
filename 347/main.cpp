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
	// https://leetcode.com/problems/top-k-frequent-elements/description/
	std::vector<int> topKFrequent(const std::vector<int>& nums, int k)
	{
		// If there's only 1, return it.
		if (nums.size() == 1)
		{
			return {nums[0]};
		}

		// Store frequencies in hash map.
		std::unordered_map<int, int> frequencies;
		for (auto num : nums)
		{
			frequencies[num]++;
		}

		// Now order frequencies in priority queue.
		std::priority_queue<std::pair<int, int>> orderedFrequencies;
		for (auto ii = frequencies.begin(); ii != frequencies.end(); ii++)
		{
			orderedFrequencies.push({ii->second, ii->first});
		}
		
		std::vector<int> result;

		// Get the top k frequencies
		while (k > 0)
		{
			result.push_back(orderedFrequencies.top().second);
			orderedFrequencies.pop();
			k--;
		}

		return result;
	}
};

int main()
{
	// Example 1: Expected (1,2) -- in any order
	std::vector<int> nums{1,1,1,2,2,3};
	auto temp = Solution().topKFrequent(nums, 2);
	for (auto ii : temp)
	{
		std::cout << ii << ' ';
	}

	std::cout << std::endl;

	// Example 2: Expected (1)
	nums = {1};
	temp = Solution().topKFrequent(nums, 2);
	for (auto ii : temp)
	{
		std::cout << ii << ' ';
	}

	std::cout << std::endl;
	return 0;
}