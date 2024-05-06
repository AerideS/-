#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int number;
int INF = 10000;

vector<pair<int, int>> a[30001];
int d[30001];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main() {
	int n, m, c;
	cin >> n >> m >> c;

	for (int i = 0; i < 30000; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int src; int des; int dis;
		cin >> src >> des >> dis;
		a[src].push_back(make_pair(des, dis));
	}

	dijkstra(c);

	int max = -1;
	int count = -1;
	for (int i = 0; i < n; i++) {
		if (d[i] != INF) {
			if (max < d[i]) {
				max = d[i];
				count++;
			}
		}
	}
	cout << count << " " << max;
}