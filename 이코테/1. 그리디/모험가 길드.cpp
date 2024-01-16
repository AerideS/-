#include<iostream>
#include<string>
#include <map>

using namespace std;

int main() {
	map<int, int> map;
	int num;
	string s;
	int count = 0;

	cin >> num; 
	getline(cin, s);
	getline(cin, s);
	for (int i = 1; i <= num; i++) {
		map.insert(pair<int, int>(i, 0));
	}

	for (int i = 0; i < num; i++) {
		map[s.at(i * 2) - '0'] += 1;
	}

	for (int i = 1; i <= num; i++) {
		count += map[i] / i;
	}

	//for (int i = 1; i <= num; i++) {
	//	cout << i << " " << map[i] << endl;
	//}

	cout << count;
}