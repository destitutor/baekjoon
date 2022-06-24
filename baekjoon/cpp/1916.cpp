#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

using point = pair<int, int>;
#define MAX_VERTEX 1001
vector<point> adj[MAX_VERTEX];

int solve(int n, int start, int destination) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;

    priority_queue<point, vector<point>, greater<point>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int source = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[source] < cost)
            continue;

        for (int i = 0; i < adj[source].size(); i++) {
            int nextNode = adj[source][i].first;
            int nextCost = cost + adj[source][i].second;

            if (dist[nextNode] > nextCost) {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }
    return dist[destination];
}

int main() {
    fastio;
    
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int sa, sb;
    cin >> sa >> sb;
    cout << solve(n, sa, sb) << '\n';
}