#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* 선택정렬 */

void main() {
	int n = 10;
	vector<int> arr= {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

	for (int i = 0; i < arr.size(); i++) {
		int minIndex = arr[i];
		for (int j = i+1; j < arr.size(); j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}

	for (int i : arr) {
		cout << i << " ";
	}
}