#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/*
    1. keymap의 원소 string에 대해 각 문자를 map에 저장한다.
    2. map이 비어있거나 or 만약 map에 해당 문자가 있다면 크기를 비교해서 더 작으면 갱신
*/

vector<int> solution(vector<string> keymap, vector<string> targets) {
    map<char, int> m;
    vector<int> answer;
    int total = 0;
    
    for (string s : keymap) {
        for (char c : s) {
            int index = s.find(c);
            if (m.find(c) == m.end() || m[c] > index) {
                m[c] = index;
            }
        }
    }

    for(string s : targets) {
        for (char c : s) {
            if (m.find(c) == m.end()) {
                total = -1;
                break;
            }
            else {
                total += m[c] + 1;
            }
        }
        answer.push_back(total);
        total = 0;
    }
    return answer;
}

int main() {
    vector<string> keymap = {"BC" };
    vector<string> targets = { "AC","BC" };
    vector<int> result = solution(keymap, targets);

    for (auto number : result) {
        cout << number << " ";
    }
    return 0;
}