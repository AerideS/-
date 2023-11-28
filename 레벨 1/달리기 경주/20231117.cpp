#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
    1. 사람 이름 부르면 등수 -1
    2. 앞 사람 등수 +1

    [문제점]
    key 값으로 value 값을 찾기가 어려움 => 해결방안 : 이름-순위, 순위-이름과 같이 2개의 map만들어서 관리

    [느낀점]
    시간 = k 1/공간 => 트레이드 오프 관계 인 것 같다. 시간 오버가 뜨면 1. 더 좋은 알고리즘 찾기 2. 공간 복잡도를 높이고 방법 활용
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