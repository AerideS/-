#include <iostream>
#include <vector>

using namespace std;

int main() {
	int number;
	cin >> number;
	vector<int> table = { 5, 3, 2, 1 };
	vector<int> dp;
	for (int i = 0; i <= 30001; i++)
		dp.push_back(30000);
	dp[1] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= number; j++) {
			if (i == 3)
				dp[j + table[i]] = min(dp[j + table[i]], dp[j] + 1);
			else {
				dp[j * table[i]] = min(dp[j * table[i]], dp[j] + 1);
			}
		}
	}
	cout << dp[number];
}