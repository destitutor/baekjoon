#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

int maps[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int dj[] = {1, -1, 0, 0}, di[] = {0, 0, 1, -1};

int main() {
    fastio;
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maps[i][j];
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ni = ci + di[i], nj = cj + dj[i];

            if (!(ni >= 0 && ni < n) || !(nj >= 0 && nj < m)) continue;
            if (maps[ni][nj] != 0 && !visited[ni][nj]) {
                visited[ni][nj] = true;
                dist[ni][nj] = dist[ci][cj] + 1;
                q.push({ni, nj});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (maps[i][j] == 0) cout << "0 ";
                else cout << -1 << " ";
            } else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}