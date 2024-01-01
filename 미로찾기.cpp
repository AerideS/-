/*
	πÃ∑Œ≈ª√‚
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> graph, int x, int y) {
	vector<int> dx = { -1, 1, 0, 0 };
	vector<int> dy = { 0, 0, -1, 1 };
	queue<vector<int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		x = q.front()[0];
		y = q.front()[1];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i]; 

			if (nx < 0 || nx > 2 || ny < 0 || ny > 2) {
				continue;
			}
			if (graph[nx][ny] == 0) {
				continue;
			}

			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return graph[2][2];
}

void main() {
	vector<vector<int>> graph = {
		{1, 1, 0},
		{0, 1, 0},
		{0, 1, 1}
	};

	cout << bfs(graph, 0, 0);
}