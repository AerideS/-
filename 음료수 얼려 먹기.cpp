#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool dfs(vector<vector<int>>& graph, int row, int col) {
	if (row <= -1 || row >= 3 || col <= -1 || col >= 3) {
		return false;
	}
	if (graph[row][col] == 0) {
		graph[row][col] = 1;
		dfs(graph, row-1, col);
		dfs(graph, row + 1, col);
		dfs(graph, row, col - 1);
		dfs(graph, row, col + 1);
		return true;
	}
	return false;
}

void main() {
	int result = 0;

	// graph 자체가 visited 역할
	vector<vector<int>> graph = {
		{0, 0, 1},
		{0, 1, 0},
		{1, 0, 1}
	};

	// 모든 지점에 대해서 DFS 수행
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[0].size(); j++) {
			if (dfs(graph, i, j) == true) {
				result++;
			}
		}
	}

	cout << result;
}