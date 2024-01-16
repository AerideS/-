#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N, K;
	int count = 0;
	cin >> N >> K;

	while (N != 1) {
		if (N < K) {
			count++;
			N -= 1;
		}
		else if (N % K != 0) {
			count += N % K;
			N -= N % K;
		}
		else {
			count += 1;
			N /= K;
		}
	}

	cout << count;
}