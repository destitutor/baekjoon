#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

#define MAX_COUNT 100000
bool visited[MAX_COUNT + 1];
int parent[MAX_COUNT + 1];
vector<int> v[MAX_COUNT + 1];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];

            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }
}

int main() {
    fastio;
    
    int n;
    cin >> n;

    int s, d;
    for (int i = 0; i < n; i++) {
        cin >> s >> d;
        v[s].push_back(d);
        v[d].push_back(s);
    }
    bfs(1);
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
}