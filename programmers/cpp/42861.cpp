#include <bits/stdc++.h>
using namespace std;

#define MAX_ISLANDS 100
int parent[MAX_ISLANDS];

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y) parent[x] = y;
    else parent[y] = x;
}

int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i < n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), [](auto& c1, auto& c2) {
        return c1[2] < c2[2]; });

    int cost = 0;
    for (int i = 0; i < costs.size(); i++) {
        if (find(costs[i][0]) != find(costs[i][1])) {
            cost += costs[i][2];
            merge(costs[i][0], costs[i][1]);
        }
    }
    return cost;
}