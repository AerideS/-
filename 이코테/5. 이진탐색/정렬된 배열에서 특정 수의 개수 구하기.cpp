#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int counterByRange(vector<int>& v, int leftValue, int rightValue) {
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int n, x;
vector<int> v;

int main() {
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int count = counterByRange(v, x, x);

	if (count == 0)
		cout << -1;
	else
		cout << count;
}