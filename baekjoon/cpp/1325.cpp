#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

#define MAX_COMPUTER 10000
vector<int> v[MAX_COMPUTER + 1];
bool visited[MAX_COMPUTER + 1];

int bfs(int start) {
    int result = 1;
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
                result++;
                q.push(next);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    return result;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    int s, d;
    for (int i = 0; i < m; i++) {
        cin >> s >> d;
        v[d].push_back(s);
    }

    int maxCount = INT_MIN;
    vector<int> answers;
    for (int i = 1; i <= n; i++) {
        int count = bfs(i);
        if (maxCount < count) {
            answers.clear();
            maxCount = count;
            answers.push_back(i);
        } else if (maxCount == count) answers.push_back(i);
    }
    
    for (int i = 0; i < answers.size(); i++)
        cout << answers[i] << ' ';
}