#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool have_number(vector<int> done, int j) {
    for (int i = 0; i < done.size(); i++) {
        if (done[i] == j)
            return true;
    }
    return false;
}

int solution(vector<vector<int>> jobs) {
    int cur = 0; int wait = 0; 
    vector<int> avail;
    vector<int> done;

    for (int i = 0; i < jobs.size(); i++) {
        for (int j = 0; j < jobs.size(); j++) {
            if(!have_number(done, j))
                if (cur >= jobs[j][0])
                    avail.push_back(j);
        }
        if (avail.empty())
            continue;

        int timeMin = jobs[avail[0]][1];
        int timeIndex = avail[0];

        for (auto index : avail) {
            if (timeMin >= jobs[index][1]) {
                timeMin = jobs[index][1];
                timeIndex = index;
            }
        }

        cur += jobs[timeIndex][1];
        wait += cur - jobs[timeIndex][0];
        done.push_back(timeIndex);

        avail = {};
    }
    int avg_wait = wait / jobs.size();
    return avg_wait;
}

void main() {
    vector<vector<int>> jobs = { {0, 9} ,{0, 4},{0,5},{0,7},{0,3} };
    cout << solution(jobs);
}