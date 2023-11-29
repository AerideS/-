#include <iostream>
#include <vector>

using namespace std;

/*
	start = section[0]
	count = 1
	for i in [1, n] :
		if( (section[i] - start) >= m)
			count++
			start = section[i]
		endif
		else 
			continue
		endelse
		

*/

int solution(int n, int m, vector<int> section) {
	int answer = 1;
	int start = section[0];
	for (int i = 0; i < section.size(); i++) {
		if ((section[i] - start) >= m) {
			answer++;
			start = section[i];
		}
		else {
			continue;
		}
	}
	return answer;
}

int main() {
	int n = 8;
	int m = 4;
	vector<int> section = { 2, 3, 6 };

	cout << solution(n, m, section);
	return 0;
}