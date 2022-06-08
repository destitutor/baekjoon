#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE (100 + 1)
#define MAX_DIST 123456789
int castle[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int di[] = { 0, 0, 1, -1 }, dj[] = { 1, -1, 0, 0 };

struct CurrentState {
    int distance;
    int i;
    int j;
};

int bfs(int si, int sj, int fi, int fj, int n, int m) {
    queue<CurrentState> q;
    q.push({ 0, si, sj });
    visited[si][sj] = true;

    while (!q.empty()) {
        CurrentState cs = q.front();
        q.pop();

        if (cs.i == fi && cs.j == fj)
            return cs.distance;

        for (int i = 0; i < 4; i++) {
            int ni = cs.i + di[i], nj = cs.j + dj[i];
            if (!(ni >= 0 && ni < n) || !(nj >= 0 && nj < m)) continue;
            if (!visited[ni][nj] && castle[ni][nj] != 1) {
                visited[ni][nj] = true;
                q.push({ cs.distance + 1, ni, nj });
            }
        }
    }
    return MAX_DIST;
}

int main() {
    fastio;
    int n, m, t;
    cin >> n >> m >> t;

    int swordI, swordJ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> castle[i][j];
            if (castle[i][j] == 2) {
                swordI = i;
                swordJ = j;
            }
        }
    }

    int dist1 = bfs(0, 0, swordI, swordJ, n, m); // 검 구해서 가기
    dist1 += (n - 1) - swordI + (m - 1) - swordJ;

    memset(visited, 0, sizeof(bool) * MAX_SIZE * MAX_SIZE);
    int dist2 = bfs(0, 0, n - 1, m - 1, n, m); // 그냥 가기

    int minDist = min(dist1, dist2);
    if (minDist == MAX_DIST || minDist > t) {
        cout << "Fail\n";
    } else {
        cout << minDist << '\n';
    }
}