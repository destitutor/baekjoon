#include <bits/stdc++.h>
using namespace std;

#define has(a) (building.find(pred[(a)]) != building.end())

bool isValid(set<vector<int>>& building) {
    for (auto& build : building) {
        int x = build[0], y = build[1], a = build[2];

        if (a == 0) { // 기둥
            // (0) 바닥인 경우(y == 0)
            // (1) 아래 쪽에 기둥이 있는 경우
            // (2) 오른쪽으로 보가 있는 경우
            // (3) 왼쪽으로 보가 있는 경우
            vector<int> pred[3] = { { x, y - 1, 0 }, { x, y, 1 }, { x - 1, y, 1 } };
            if (y == 0 || has(0) || has(1) || has(2)) continue;
            return false;
        } else { // 보
            // (1) 아래 쪽에 기둥이 있는 경우
            // (2) 오른쪽에 기둥이 있는 경우
            // (3) 오른쪽에 보가 있는 경우 AND 왼쪽에 보가 있는 경우
            vector<int> pred[4] = { { x, y - 1, 0 }, { x + 1, y - 1, 0 }, { x + 1, y, 1 }, { x - 1, y, 1 } };
            if (has(0) || has(1) || (has(2) && has(3))) continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> building;

    for (auto& frame : build_frame) {
        vector<int> v = { frame[0], frame[1], frame[2] };

        if (frame[3] == 0) { // 구조물 삭제
            building.erase(v);
            if (!isValid(building))
                building.insert(v);
        } else { // 구조물 설치
            building.insert(v);
            if (!isValid(building))
                building.erase(v);
        }
    }

    for (auto& build : building)
        answer.push_back(build);
    return answer;
}