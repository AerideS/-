#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/*
    1. keymap�� ���� string�� ���� �� ���ڸ� map�� �����Ѵ�.
    2. map�� ����ְų� or ���� map�� �ش� ���ڰ� �ִٸ� ũ�⸦ ���ؼ� �� ������ ����
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