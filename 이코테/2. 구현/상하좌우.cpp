#include<iostream>
#include<vector>
#include<string>


using namespace std;

int main() {
	int n;
	string s;
	vector<int> direction;
	int position[2] = { 1, 1 };
	int dx[4] = {1, 0, -1, 0}; // R U L D
	int dy[4] = { 0, -1, 0, 1 }; 

	cin >> n;
	getline(cin, s);
	getline(cin, s);

	int* map = new int[(n + 1) * (n + 1)];

	for (int i = 0; i <= s.length(); i += 2) {
		if (s[i] == 'R')
			direction.push_back(0);
		else if (s[i] == 'U')
			direction.push_back(1);
		else if (s[i] == 'L')
			direction.push_back(2);
		else if (s[i] == 'D')
			direction.push_back(3);
	}

	for (int d : direction) {
		cout << d << " ";
	}

	cout << endl;

	for (auto a : direction) {
		if (((position[0] + dy[a]) >= 1) && ((position[0] + dy[a]) <= n)) {
			if (((position[1] + dx[a]) >= 1) && ((position[1] + dx[a]) <= n)) {
				position[1] += dx[a];
				position[0] += dy[a];
			}
		}
	}

	cout << position[0] << " " << position[1];
}