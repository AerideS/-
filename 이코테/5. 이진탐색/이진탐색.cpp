#include <iostream>
#include <vector> 

using namespace std;

int binary_search(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target == arr[mid]) {
			return mid;
		}
		else if (target < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return NULL;
}

int main() {
	int n, target;
	vector<int> arr;
	cin >> n >> target;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	int result = binary_search(arr, 7, 0, arr.size() - 1);
	if (result == NULL)
		cout << "원소가 존재하지 않습니다.";
	else
		cout << result + 1;
}