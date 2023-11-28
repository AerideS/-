#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int time = 0; int wait = 0; int size = jobs.size();

    sort(jobs.begin(), jobs.end());
    while (!jobs.empty()) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq; 
        for (int i = 0; i < jobs.size(); i++) {
            if (time >= jobs[i][0]) {
                pq.push(jobs[i]);
            }
        }
        if (pq.empty()) {
            time = jobs[0][0];
            continue;
        }
        else {
            vector<int> add = pq.top();
            time += add[1]; 
            wait += time - add[0];

            int index = 0;
            for (int i = 0; i < jobs.size(); i++) {
                if ((add[0] == jobs[i][0]) && (add[1] == jobs[i][1])) {
                    index = i;
                }
            }
            jobs.erase(jobs.begin() + index);
        }
    }

    int avg_wait = wait / size;
    return avg_wait;
}

int main() {
    vector<vector<int>> jobs = { {1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3} };
    cout << solution(jobs);

    return 0;
}
