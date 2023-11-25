#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    1. op�� E, W ��� (1) ���� �� �¿� �κ� ��ֹ� �˻� (2) ���� �� �¿� ��� �˻�
    2. op�� N, S ��� (1) ���� �� ���� �κ� ��ֹ� �˻� (2) ���� �� ���� ��� �˻�

    Position = ������ġ ã��
    for route 
        if op�� E, W ��� 
            (1) ���� �� �¿� �κ� ��ֹ� �˻� (2) ���� �� �¿� ��� �˻�
            position �̵�
        end if
        else if op�� N, S ���
            (1) ���� �� ���� �κ� ��ֹ� �˻� (2) ���� �� ���� ��� �˻�
            position �̵�
        end else if
    end for
    return position;
*/

// ��� üũ �Լ�
bool check_boundary(vector<int> position, vector<string> park, string route) {
    vector<int> newPosition = position;
    string move;
    move.push_back(route[2]);
    if (route[0] == 'E') {
        newPosition[0] = newPosition[0] + stoi(move);
        //cout << newPosition[0] << " " << park[0].size() << endl;;
        if (newPosition[1] < park[0].size()) {
            return true;
        }
        else return false;
    }
    else if (route[0] == 'W') {
        newPosition[0] = newPosition[0] - stoi(move);
        //cout << newPosition[0] << " " << park[0].size() << endl;;
        if (newPosition[1] > -1) {
            return true;
        }
        else return false;
    }
    else if (route[0] == 'S') {
        newPosition[0] = newPosition[1] + stoi(move);
        //cout << newPosition[1] << " " << park[1].size() << endl;;
        if (newPosition[1] < park.size()) {
            return true;
        }
        else return false;
    }
    else if (route[0] == 'N') {
        newPosition[0] = newPosition[1] - stoi(move);
        //cout << newPosition[1] << " " << park[1].size() << endl;;
        if (newPosition[1] > -1) {
            return true;
        }
        else return false;
    }

    return false;
}

bool check_obstacle(vector<int> position, vector<string> park, string route) {
    string move;
    move.push_back(route[2]);
    int imove = stoi(move);

    try {
        if (route[0] == 'E') {
            for (int i = 1; i < imove + 1; i++) {
                if (position[1] + i > park[0].size() - 1) {
                    throw false;
                }
                if (park[position[0]][position[1] + i] == 'X') {
                    return false;
                }
            }
            return true;
        }
        else if (route[0] == 'W') {
            for (int i = 1; i < imove + 1; i++) {
                if (position[1] - i < 0) {
                    throw false;
                }
                if (park[position[0]][position[1] - i] == 'X') {
                    return false;
                }
            }
            return true;
        }
        else if (route[0] == 'N') {
            for (int i = 1; i < imove + 1; i++) {
                if (position[0] - i < 0) {
                    throw false;
                }
                if (park[position[0] - i][position[1]] == 'X') {
                    return false;
                }
            }
            return true;
        }
        else if (route[0] == 'S') {
            for (int i = 1; i < imove + 1; i++) {
                if (position[0] + i > park.size() - 1) {
                    throw false;
                }
                if (park[position[0] + i][position[1]] == 'X') {
                    return false;
                }
            }
            return true;
        }
    }
    catch(bool error) {
        return false;
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer = { -1, -1 };

    // ���� ��ġ ã��
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == 'S') {
                answer = { i, j };
                break;
            }
        }
        if ( (answer[0] != -1) && (answer[1] != -1)) {
            break;
        }
     }

    for (string route : routes) {
        string move;
        move.push_back(route[2]);
        int imove = stoi(move);
        if (check_boundary(answer, park, route)) {
            if (check_obstacle(answer, park, route)) {
                if (route[0] == 'E') {
                    answer[1] += imove;
                }
                else if (route[0] == 'W') {
                    answer[1] -= imove;
                }
                else if (route[0] == 'N') {
                    answer[0] -= imove;
                }
                else if (route[0] == 'S') {
                    answer[0] += imove;
                }
            }
        }
    }

    return answer;
}

int main() {
    vector<string> park = { "SOO", "OOO", "OOO" };
    vector<string> routes = { "E 2","S 2","W 1" };
    vector<int> answer = solution(park, routes);

    cout << answer[0] << " " << answer[1];
}