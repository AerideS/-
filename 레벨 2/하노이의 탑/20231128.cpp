#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
	�ϳ��� Ÿ���� ����Լ��� ���µ� Ÿ���� ����
	1. �ɰ� �� �ִ� ������ �ݺ��Ǵ� ������.
	2. ó�� ȣ��Ǵ� ���°� ���� �������� ����ǰ�, ���� �� ���·� �����. hanoi(1, start, end, via)�� ���� ���� ������ ����

	�׷��ٸ� � ��Ģ�� �ֳ�.
	�������� ������ ������ ���� ���� ������ ������ �ذ��ϴ� ���� �߿�! (Divide and conquer)
	
	(1) n=1��� �����ϸ�
		1. hanoi(1, start(1), end(3), via(2)) �� ����

	(2) n=2��� �����ϸ�
		1. hanoi(2, start(1), end(3), via(2)) - 1. hanoi(1, start(1), via(2), end(3))
											  - 2. return {start(1), end(3)}
											  - 3. hanoi(1, via(2), end(3), start(1))
	(3) n=3��� �����ϸ�
		1. hanoi(3, start(1), end(3), via(2)) - 1 hanoi(2, start(1), via(2), end(3)) - 1. hanoi(1, start(1), end(3), via(2))
																					 - 2. return {start(1), via(2)}
																					 - 3. hanoi(1, end(3), via(2), start(1))
											  - 2 return {start(1), end(3)}
											  - 3 hanoi(2, via(2), end(3), start(1)) - 1. hanoi(1, via(2), start(1), end(3))
																					 - 2. return {via(2), end(3)}
																					 - 3. hanoi(1, start(1), end(3), via(2))

	��, �� n���� ������ �ִٸ�
	1. n-1���� ���� via�� �ű��
	2. ���� ū ������ end�� �ű��
	3. n-1���� ���� end�� �ű�� ������ �ݺ��̶�� ���� ������ ���� �� �� ����.
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