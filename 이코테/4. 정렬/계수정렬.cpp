#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	vector<int> arr = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };
	map<int, int> list;
	for(int i = 0; i < 10; i++)
		list.insert({ i, 0 });

	for (int i : arr) {
		list[i] += 1;
	}

	for (int i = 0; i < 10; i++) {
		int count = list[i];
		for (int j = 0; j < count; j++) {
			cout << i << " ";
		}
	}
}