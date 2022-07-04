#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;

int N, M;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

inline bool isWithinRange(int x, int y) {
    return (0 <= x && x < M) && (0 <= y && y < N);
}

bool isFinished(vector<vector<int>>& board, Point& point) {
    for (int i = 0; i < 4; i++) {
        int nx = point.second + dx[i], ny = point.first + dy[i];
        if (isWithinRange(nx, ny) && board[ny][nx] == 1)
            return false;
    }
    return true;
}

pair<bool, int> solve(vector<vector<int>>& board, Point aloc, Point bloc) {
    // 더이상 현재 플레이어가 이동할 공간이 없다. 따라서 다른 플레이어의 승리다.
    if (isFinished(board, aloc)) return { false, 0 };
    // 같은 위치에 있는 경우 현재 플레이어가 움직이면 다른 플레이어는 탈락한다. 즉, 현재 플레이어는 무조건 승리한다.
    if (aloc == bloc) return { true, 1 };

    bool canWin = false;
    int minTurn = INT_MAX, maxTurn = 0;

    for (int i = 0; i < 4; i++) {
        int nx = aloc.second + dx[i], ny = aloc.first + dy[i];
        if (!isWithinRange(nx, ny) || board[ny][nx] == 0) continue;

        // DFS
        board[aloc.first][aloc.second] = 0;
        // 순서를 바꿔가며(즉, 상대방에게 턴을 넘기며) 재귀적으로 실행한다.
        pair<bool, int> result = solve(board, bloc, { ny, nx });
        board[aloc.first][aloc.second] = 1;

        // 다음 순번이 졌으므로 현재 순번은 이겼다는 의미다.
        if (!result.first) {
            canWin = true;
            minTurn = min(minTurn, result.second);
        } 
        // 다음 순번이 이겼으므로 현재 순번은 졌다는 의미다.
        // 이기는 경우의 수가 있다면(canWin) 보존한다.
        else if (!canWin) {
            maxTurn = max(maxTurn, result.second);
        }
    }

    // 승리할 수 있을 때는 최소 턴 수를, 무조건 패배할 시에는 최대 턴 수를 반환한다.
    int turn = canWin ? minTurn : maxTurn;
    return { canWin, 1 + turn };
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size(), M = board[0].size();
    return solve(board, { aloc[0], aloc[1] }, { bloc[0], bloc[1] }).second;
}