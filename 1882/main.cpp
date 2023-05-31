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
	// https://leetcode.com/problems/process-tasks-using-servers/
	std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks)
	{
		auto freeCompare = [](const std::pair<int, int>& a, const std::pair<int, int>& b)
		{
			return (a.first == b.first) ? a.second > b.second : a.first > b.first;
		};

		// Create a priority queue that has the lowest weight at the top, or lowest index if weights are equal.
		// A pair is used to store the weight along with the index of the server.
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
			decltype(freeCompare)> freeServers(freeCompare);
		for (int ii = 0; ii < servers.size(); ii++)
		{
			freeServers.push({servers[ii], ii});
		}

		// If there's only one task, just take the lowest weight.
		if (tasks.size() == 1)
		{
			return {freeServers.top().second};
		}
		
		// Next, create a priority queue that stores the server based on least amount of time remaining.
		// If time remainings are equal, use same weight/index rules for servers as above.
		auto busyCompare = [&](const std::pair<int, int>& a, const std::pair<int, int>& b)
		{
			if (a.first != b.first)
			{
				return a.first > b.first;
			}

			return (servers[a.second] == servers[b.second]) ? a.second > b.second :
				servers[a.second] > servers[b.second];
		};

		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(busyCompare)>
			busyServers(busyCompare);
		std::vector<int> result;
		for (int ii = 0; ii < tasks.size(); ii++)
		{
			// If a server has completed, add to free servers.
			while (busyServers.size() && busyServers.top().first == ii)
			{
				freeServers.push({servers[busyServers.top().second], busyServers.top().second});
				busyServers.pop();
			}

			// If a free server is available, use the lowest weight.
			if (freeServers.size())
			{
				result.push_back(freeServers.top().second);
				busyServers.push({ii + tasks[ii], freeServers.top().second});
				freeServers.pop();
			}

			// Otherwise, use first server that will become available.
			else
			{
				result.push_back(busyServers.top().second);
				busyServers.push({busyServers.top().first + tasks[ii], busyServers.top().second});
				busyServers.pop();
			}
		}

		return result;
	}
};

int main()
{
	// Example 1: Expected (2,2,0,2,1,2)
	std::vector<int> servers{3, 3, 2},
		tasks{1,2,3,2,1,2};
	auto temp = Solution().assignTasks(servers, tasks);
	for (int ii = 0; ii < temp.size(); ii++)
	{
		std::cout << temp[ii] << ' ';
	}

	std::cout << std::endl;

	// Example 2: Expected(1,4,1,4,1,3,2)
	servers = {5,1,4,3,2};
	tasks = {2,1,2,4,5,2,1};
	temp = Solution().assignTasks(servers, tasks);
	for (int ii = 0; ii < temp.size(); ii++)
	{
		std::cout << temp[ii] << ' ';
	}

	std::cout << std::endl;
	return 0;
}