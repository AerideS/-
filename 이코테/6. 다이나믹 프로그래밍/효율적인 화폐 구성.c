#include <iostream>
#include <vector>

using namespace std;

int main() {
	int cntTable;
	int number;
	vector<int> table;
	vector<int> dp(number + 1, 10001);

	cin >> cntTable >> number;
	for (int i = 0; i < cntTable; i++) {
		int tmp;
		cin >> tmp;
		table.push_back(tmp);
	}
	
	dp[0] = 0;
	for (int i = 0; i < cntTable; i++) {
		for (int j = 0; j < number; j++) {
			dp[j + table[i]] = min(dp[j + table[i]], dp[j] + 1);
		}
	}

	if (dp[number] == 10001)
		cout << -1;
	else 
		cout << dp[number];
}