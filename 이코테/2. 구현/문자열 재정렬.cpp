#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	vector<int> number;
	vector<char> ch;
	int count = 0;
	cin >> s;

	for (char c : s) {
		if (c < 'A') {
			number.push_back(c - '0');
		}
		else {
			ch.push_back(c - 'A');
		}
	}

	sort(ch.begin(), ch.end());

	for (char c : ch) {
		cout << char(c + 'A');
	}
	for (int i : number) {
		count += i;
	}
	cout << count;
}