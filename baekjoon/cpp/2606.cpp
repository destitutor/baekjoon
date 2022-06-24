#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

#define MAX_COMPUTER 100
vector<int> v[MAX_COMPUTER + 1];
bool visited[MAX_COMPUTER + 1];

int bfs(int start) {
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (int i = 0; i < v[c].size(); i++) {
            int next = v[c][i];

            if (!visited[next]) {
                visited[next] = true;
                count++;
                q.push(next);
            }
        }
    }
    return count;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    int s, d;
    for (int i = 0; i < m; i++) {
        cin >> s >> d;
        v[s].push_back(d);
        v[d].push_back(s);
    }

    int answer = bfs(1);
    cout << answer << '\n';
}