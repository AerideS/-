#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
    1. photo�� ���Ұ� �����Ѵٸ� �Ʒ� ������ �ݺ�
    2. photo�� ���ҿ��� name �� �̸��� �ִ��� Ȯ��
    3. �ִٸ� �ε����� Ȯ���ϰ� yearning�� �ε��� ���� �־ ���� �ջ�

    find �Լ��� ����ϸ� ���� Ǯ �� ���� ������ ����.
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