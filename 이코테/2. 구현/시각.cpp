#include<iostream>

/*
[case]
1. 시간 단위가 3인 경우	59 * 59
2. 분 단위가 3인 경우		59
3. 초 단위가 3인 경우		18
*/

using namespace std;

int main() {
	int input;
	int h = 0;
	int m = 0;
	int count = 0;
	cin >> input;

	while (h-1 != input) {
		if (h / 10 == 3 || h % 10 == 3) {
			count += 60 * 60;
			h++;
			continue;
		}
		for (int m = 0; m < 60; m++) {
			if (m / 10 == 3 || m % 10 == 3)
				count += 60;
			else
				count += 15;
		}
		h++;
	}
	cout << count;
}