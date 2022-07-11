#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

int paper[500][500];
bool visited[500][500];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int bfs(int sr, int sc, int n, int m) {
    int area = 1;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dy[i], nc = cc + dx[i];

            if (!(nr >= 0 && nr < n) || !(nc >= 0 && nc < m)) continue;
            if (!visited[nr][nc] && paper[nr][nc] == 1) {
                visited[nr][nc] = true;
                q.push({nr, nc});
                area++;
            }
        }
    }
    return area;
}

int main() {
    fastio;
    int n, m;
    int count = 0, maxArea = 0;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> paper[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == 1 && !visited[i][j]) {
                int result = bfs(i, j, n, m);
                maxArea = max(maxArea, result);
                count++;
            }
        }
    }

    cout << count << '\n' << maxArea;
}