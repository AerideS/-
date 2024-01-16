#include<iostream>
#include<vector>
#include <string>

using namespace std;

int main() {
	int sum = 0;
	string s;
	cin >> s;

	sum += int(s.at(0) - '0');
	for (int i = 1; i < s.length(); i++) {
		if ((s.at(i) - '0') <= 1) {
			sum += int(s.at(i) - '0');
		}
		else {
			sum *= int(s.at(i) - '0');
		}
	}

	cout << sum;
}