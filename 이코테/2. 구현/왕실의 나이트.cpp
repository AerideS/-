#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<int, char> intchar;
	map<char, int> charint;
	string input;
	int col; int row;
	int count = 0;

	intchar.insert({ 1, 'a' }); intchar.insert({ 2, 'b' }); intchar.insert({ 3, 'c' }); intchar.insert({ 4, 'd' }); intchar.insert({ 5, 'e' }); intchar.insert({ 6, 'f' }); intchar.insert({ 7, 'g' }); intchar.insert({ 8, 'h' });
	charint.insert({ 'a', 1 }); charint.insert({ 'b', 2 }); charint.insert({ 'c', 3 }); charint.insert({ 'd', 4 }); charint.insert({ 'e', 5 }); charint.insert({ 'f', 6 }); charint.insert({ 'g', 7 }); charint.insert({ 'h', 8 });

	cin >> input;
	col = charint[input[0]];
	row = input[1] - '0';

	// 1. row + 2, col -+ 1
	// 2. row - 2, col -+ 1
	// 3. row +- 1, col + 2
	// 4. row +- 1, col - 2

	if ((row + 2) >= 1 && (row + 2) <= 8)
		if ((col - 1) >= 1 && (col - 1) <= 8)
			count++;
	if ((row + 2) >= 1 && (row + 2) <= 8)
		if ((col + 1) >= 1 && (col + 1) <= 8)
			count++;
	if ((row - 2) >= 1 && (row - 2) <= 8)
		if ((col - 1) >= 1 && (col - 1) <= 8)
			count++;
	if ((row - 2) >= 1 && (row - 2) <= 8)
		if ((col + 1) >= 1 && (col + 1) <= 8)
			count++;
	if ((row + 1) >= 1 && (row + 1) <= 8)
		if ((col + 2) >= 1 && (col + 2) <= 8)
			count++;
	if ((row - 1) >= 1 && (row - 1) <= 8)
		if ((col + 2) >= 1 && (col + 2) <= 8)
			count++;
	if ((row + 1) >= 1 && (row + 1) <= 8)
		if ((col - 2) >= 1 && (col - 2) <= 8)
			count++;
	if ((row - 1) >= 1 && (row - 1) <= 8)
		if ((col - 2) >= 1 && (col - 2) <= 8)
			count++;

	cout << count;
}