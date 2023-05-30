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
	// https://leetcode.com/problems/count-servers-that-communicate/description/
	// Time complexity: O(m * n)
	int countServers(const std::vector<std::vector<int>>& grid)
	{
		// Two array that store which columns and rows already have a server present.
		// 'Int' type is used because there must be more than one server on any column or row for a connection.
		std::vector<int> columns(grid.size(), 0);
		std::vector<int> rows(grid[0].size(), 0);
		int count = 0;

		// First, go through all servers and find which rows and columns have servers.
		for (int ii = 0; ii < grid.size(); ii++)
		{
			for (int jj = 0; jj < grid[ii].size(); jj++)
			{
				if (!grid[ii][jj])
					continue;
				columns[ii]++;
				rows[jj]++;
			}
		}

		// Next, see which servers exist on a row/column with more than one server and add to count.
		for (int ii = 0; ii < grid.size(); ii++)
		{
			for (int jj = 0; jj < grid[ii].size(); jj++)
			{
				if (grid[ii][jj] &&
					(columns[ii] > 1 || rows[jj] > 1))
				{
					count++;
				}
			}
		}

		return count;
	}
};

int main()
{
	// Example 1: 0 expected
	std::vector<std::vector<int>> example{{1,0}, {0,1}};
	std::cout << Solution().countServers(example) << std::endl;

	// Example 2: 3 expected
	example = {{1,0}, {1,1}};
	std::cout << Solution().countServers(example) << std::endl;

	// Example 3: 4 expected
	example = {{1,1,0,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,1}};
	std::cout << Solution().countServers(example) << std::endl;
	return 0;
}