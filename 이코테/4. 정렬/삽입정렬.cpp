#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* 선택정렬 */

void main() {
	int n = 10;
	vector<int> arr= {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
			else break;
		}
	}

	for (int i : arr) {
		cout << i << " ";
	}
}