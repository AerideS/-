#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> _row = { 1, 0, -1, 0 };
vector<int> _col = { 0, -1, 0, 1 };

bool dfs(vector<string>& graph, int row, int col) {
	if (row <= -1 || row >= graph.size() || col <= -1 || col >= graph[0].length())
		return false;
	for (int i = 0; i < 4; i++) {
		if (graph[row][col] == '0') {
			graph[row][col] = '1';
			dfs(graph, row - 1, col);
			dfs(graph, row, col - 1);
			dfs(graph, row + 1, col);
			dfs(graph, row, col + 1);
			return true;
		}
	}
	return false;
}

int main() {
	int row, col;
	int count = 0;
	string str;
	vector<string> graph;

	cin >> row >> col;
	cin.ignore();
	for (int i = 0; i < row; i++) {
		getline(cin, str);
		graph.push_back(str);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (dfs(graph, i, j))
				count++;
		}
	}

	cout << count << endl;

	for (auto s : graph) {
		cout << s << endl;
	}
}