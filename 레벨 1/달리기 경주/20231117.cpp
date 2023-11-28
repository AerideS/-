#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
    1. ��� �̸� �θ��� ��� -1
    2. �� ��� ��� +1

    [������]
    key ������ value ���� ã�Ⱑ ����� => �ذ��� : �̸�-����, ����-�̸��� ���� 2���� map���� ����

    [������]
    �ð� = k 1/���� => Ʈ���̵� ���� ���� �� �� ����. �ð� ������ �߸� 1. �� ���� �˰��� ã�� 2. ���� ���⵵�� ���̰� ��� Ȱ��
*/

vector<string> solution(vector<string> players, vector<string> callings) {
    map<int, string> map1;
    map<string, int> map2;
    vector<string> answer;

    for (int i = 1; i <= players.size(); i++) {
        map1.insert({i, players[i-1]});
    }
    for (int i = 1; i <= players.size(); i++) {
        map2.insert({ players[i-1], i});
    }

    int Wrank;
    string Wname;
    int Lrank;
    string Lname;
    for (auto s : callings) {
        Wrank = map2[s];
        Wname = s;

        Lname = map1[Wrank-1];
        Lrank = map2[Lname];

        map1[Wrank - 1] = Wname;
        map2[Wname] = Wrank - 1;

        map1[Lrank + 1] = Lname;
        map2[Lname] = Lrank + 1;

    }

    for (auto i : map1) {
        answer.push_back(i.second);
    }

    return answer;
}

int main() {
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings = { "kai", "kai", "mine", "mine" };
    
    vector<string> answer = solution(players, callings);
    
    for (auto s : answer)
        cout << s << " ";
    //map<string, int> map1;
    //string printArr[5];
    //map1.insert({ "A", 1 });
    //map1.insert({ "B", 2 });
    //map1.insert({ "C", 3 });
    //map1.insert({ "D", 4 });

    //int calledRank;
    //string past;
    //for (auto i : map1) {
    //    if (i.first == "C") {
    //        calledRank = i.second;
    //        map1[past] = calledRank;
    //        map1["C"] -= 1;    
    //    }
    //    past = i.first;
    //}

    //for (auto i : map1) {
    //    printArr[i.second] = i.first;
    //}

    //for (int i = 1; i < 5; i++) {
    //    cout << printArr[i];
    //}
}