#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
foreach calling
	swap(player(calling), player(calling-1)
*/

vector<string> solution(vector<string> players, vector<string> callings) {
    for (string call : callings) {
        int idx1 = find(players.begin(), players.end(), call) - players.begin();
        int idx2 = idx1 - 1;

        swap(players[idx1], players[idx2]);
    }

    vector<string> answer;
    answer = players;
    return answer;
}

int main() {
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings = { "kai", "kai", "mine", "mine" };
    
    vector<string> answer = solution(players, callings);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}