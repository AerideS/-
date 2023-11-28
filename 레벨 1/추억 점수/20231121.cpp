#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
    1. photo에 원소가 존재한다면 아래 내용을 반복
    2. photo의 원소에서 name 에 이름이 있는지 확인
    3. 있다면 인덱스를 확인하고 yearning에 인덱스 값을 넣어서 점수 합산

    find 함수를 사용하면 쉽게 풀 수 있을 것으로 보임.
*/

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    int sum = 0;
    int idx;
    vector<int> answer = {};

    for (vector<string> p : photo) {
        sum = 0;
        for (int i = 0; i < p.size(); i++) {
            idx = find(name.begin(), name.end(), p[i]) - name.begin();

            if (idx == name.size())
                sum += 0;
            else
                sum += yearning[idx];
        }
        answer.push_back(sum);
    }
    return answer;
}

int main() {
    vector<string> name = { "kali", "mari", "don" };
    vector<int> yearning = { 11, 1, 55 };
    vector<vector<string>> photo = { { "kali", "mari", "don" }, { "pony", "tom", "teddy" },
        { "con", "mona", "don"} };

    vector<int> a = solution(name, yearning, photo);
    for (int s : a) {
        cout << s << " ";
    }
}