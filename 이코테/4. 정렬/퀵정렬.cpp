#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void quickSort(vector<int>&, int, int);

int main() {
	vector<int> arr = { 5, 7, 9, 0, 3, 1, 6, 2, 4, 8 };
	quickSort(arr, 0, arr.size() - 1);

	for (int i : arr) 
		cout << i << " ";
}

void quickSort(vector<int>& arr, int start, int end) {
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		while (left <= end && arr[left] <= arr[pivot])
			left += 1;
		while (right > start && arr[right] >= arr[pivot])
			right -= 1;
		if (left > right)
			swap(arr[right], arr[pivot]);
		else
			swap(arr[left], arr[right]);

		quickSort(arr, start, right - 1);
		quickSort(arr, right + 1, end);
	}
}