#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num;
	vector<int> house;
	vector<int> dp;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		house.push_back(tmp);
	}
	
	for (int i = 0; i < num; i++) {
		if (i == 0 || i == 1)
			dp.push_back(house[i]);
		else {
			int tmp = max(dp[i - 1], dp[i - 2] + house[i]);
			dp.push_back(tmp);
		}
	}

	cout << dp[num-1];
}