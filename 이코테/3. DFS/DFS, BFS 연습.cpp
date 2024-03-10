#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void dfs(vector<vector<int>> graph, vector<bool> &visited, int index) {
	visited[index] = true;
	cout << index << " ";

	for (int v : graph[index]) {
		if (visited[v] == false) {
			dfs(graph, visited, v);
		}
	}
}

void bfs(vector<vector<int>> graph, vector<bool>& visited, int index) {
	queue<int> q;

	q.push(index);
	visited[index] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int n : graph[v]) {
			if (visited[n] == false) {
				q.push(n);
				visited[n] = true;
			}
		}
	}

}

void main() {
	vector<vector<int>> graph = {
		{},
		{2, 3, 8},
		{1, 7},
		{1, 4, 5},
		{3, 5},
		{3, 4},
		{7},
		{2, 6, 8},
		{1, 7}
	};

	vector<bool> visited;
	for (int i = 0; i < 9; i++) {
		visited.push_back(false);
	}

	//dfs(graph, visited, 1);
	bfs(graph, visited, 1);
}