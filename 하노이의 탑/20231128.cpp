#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
	하노이 타워가 재귀함수를 쓰는데 타당한 이유
	1. 쪼갤 수 있는 패턴이 반복되는 형태임.
	2. 처음 호출되는 상태가 제일 마지막에 실행되고, 바텀 업 형태로 진행됨. hanoi(1, start, end, via)가 가장 먼저 실행이 끝남

	그렇다면 어떤 규칙이 있나.
	논리적으로 복잡한 문제는 작은 문제 단위로 나눠서 해결하는 것이 중요! (Divide and conquer)
	
	(1) n=1라고 생각하면
		1. hanoi(1, start(1), end(3), via(2)) 면 끝남

	(2) n=2라고 생각하면
		1. hanoi(2, start(1), end(3), via(2)) - 1. hanoi(1, start(1), via(2), end(3))
											  - 2. return {start(1), end(3)}
											  - 3. hanoi(1, via(2), end(3), start(1))
	(3) n=3라고 생각하면
		1. hanoi(3, start(1), end(3), via(2)) - 1 hanoi(2, start(1), via(2), end(3)) - 1. hanoi(1, start(1), end(3), via(2))
																					 - 2. return {start(1), via(2)}
																					 - 3. hanoi(1, end(3), via(2), start(1))
											  - 2 return {start(1), end(3)}
											  - 3 hanoi(2, via(2), end(3), start(1)) - 1. hanoi(1, via(2), start(1), end(3))
																					 - 2. return {via(2), end(3)}
																					 - 3. hanoi(1, start(1), end(3), via(2))

	즉, 총 n개의 과정이 있다면
	1. n-1개의 링을 via로 옮기고
	2. 가장 큰 원반은 end로 옮기고
	3. n-1개의 링을 end로 옮기는 과정의 반복이라는 것을 관찰을 통해 알 수 있음.
*/



void hanoi(int n, int start, int end, int via, vector<vector<int>>& answer) {
	if (n == 1) {
		answer.push_back({ start, end });
	}
	else{
		hanoi(n - 1, start, via, end, answer);
		answer.push_back({ start, end });
		hanoi(n - 1, via, end, start, answer);
	}
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;
	hanoi(n, 1, 3, 2, answer);
	return answer;
}

int main() {
	vector<vector<int>> answer = solution(3);
	for (auto i : answer) {
		cout << i[0] << " " << i[1] << endl;
	}
	return 0;
}