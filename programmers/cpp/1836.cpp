#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100
bool visited[MAX_SIZE][MAX_SIZE];
int dj[] = { 1, -1, 0, 0 }, di[] = { 0, 0, 1, -1 };

struct Block {
    int i;
    int j;
    int direction;
    int numOfBends;
};

bool bfs(vector<string>& board, pair<int, int>& start, pair<int, int>& end) {
    memset(visited, false, MAX_SIZE * MAX_SIZE);

    queue<Block> q; // { {좌표}, 방향 }
    q.push({ start.first, start.second, -1, 0 });
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Block currentBlock = q.front();
        q.pop();

        if (currentBlock.i == end.first && currentBlock.j == end.second)
            return true;
        for (int i = 0; i < 4; i++) {
            int ni = currentBlock.i + di[i], nj = currentBlock.j + dj[i];

            if (!(ni >= 0 && ni < board.size()) || !(nj >= 0 && nj < board[0].size())) continue;
            if (!visited[ni][nj] && (board[ni][nj] == '.' || board[start.first][start.second] == board[ni][nj]) &&
                ((currentBlock.direction != i && currentBlock.numOfBends + 1 < 2) || currentBlock.direction == -1)) {
                visited[ni][nj] = true;
                q.push({ ni, nj, i, currentBlock.direction == -1 ? 0 : currentBlock.numOfBends + 1 });
            }
        }
    }
    return false;
} 

string solution(int m, int n, vector<string> board) {
    map<char, vector<pair<int, int>>> maps;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                maps[board[i][j]].push_back({ i, j });

    string answers;   
    int count = maps.size();
    while (answers.size() < count) {
        bool isRemoved = false;
        for (auto& entry : maps) {
            if (board[entry.second[0].first][entry.second[0].second] != '.') {
                bool isSuccess = bfs(board, entry.second[0], entry.second[1]);
                if (isSuccess) {
                    board[entry.second[0].first][entry.second[0].second] = '.';
                    board[entry.second[1].first][entry.second[1].second] = '.';
                    isRemoved = true;
                    answers += entry.first;
                }
            }
        }
        if (!isRemoved)
            return "IMPOSSIBLE";
    }
    return answers;
}