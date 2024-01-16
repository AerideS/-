#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> kind = { 500, 100, 50, 10 };

	int N = 1260;
	int count = 0;
	for (int money : kind) {
		int countOfKind = int(N / money);
		count += countOfKind;
		N -= money * countOfKind;
	}
	count += N;

	cout << count;
}