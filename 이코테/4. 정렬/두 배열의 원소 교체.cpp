#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int col, count;
	vector<int> a, b;

	cin >> col >> count;

	for (int i = 0; i < col; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < col; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	for (int i = 0; i < count; i++) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		swap(a[0], b[col-1]);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i : a)
		cout << i << " ";
	cout << endl;
	for (int i : b)
		cout << i << " ";


}