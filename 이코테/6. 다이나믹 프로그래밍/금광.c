#include <iostream>
#include <vector>

using namespace std;

int miner() {
	int n, m;
	vector<vector<int>> mine;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			tmp.push_back(num);
		}
		mine.push_back(tmp);
		tmp = { };
	}

	vector<vector<int>> dp;
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < m; j++) {
			tmp.push_back(0);
		}
		dp.push_back(tmp);
		tmp = { };
	}

	for (int i = 0; i < n; i++) {
		dp[i][0] = mine[i][0];
	}

	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (i == 0)
				dp[i][j] = mine[i][j] + max(dp[i][j - 1], dp[i + 1][j - 1]);
			else if (i == n - 1)
				dp[i][j] = mine[i][j] + max(dp[i - 1][j - 1], dp[i][j - 1]);
			else
				dp[i][j] = mine[i][j] + max(max(dp[i - 1][j - 1], dp[i][j - 1]), dp[i + 1][j - 1]);
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		max > dp[i][m - 1] ? max = max : max = dp[i][m - 1];
	}
	return max;
}

int main() {
	int count = 0;
	cin >> count;

	vector<int> answer = { };
	answer.push_back(miner());
	answer.push_back(miner());

	for (auto i : answer) {
		cout << i << endl;
	}
}