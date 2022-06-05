#include <bits/stdc++.h>
using namespace std;

bool isOk(vector<pair<int, int>>& cp, int i, int j, int maxCount) {
    for (int k = 0; k < cp.size(); k++) {
        int dist = abs(i - cp[k].first) + abs(j - cp[k].second);
        if (dist < maxCount)
            return false;
    }
    return true;
}

int getMinimumDist(int n, int m) {
    int maxCount = 2 * n - 2, count = maxCount;
    while (count > 0) {
        for (int si = 0; si < n; si++) {
            for (int sj = 0; sj < n; sj++) {
                vector<pair<int, int>> cp;
                cp.push_back({ si, sj });
                for (int i = si; i < n; i++)
                    for (int j = 0; j < n; j++) {
                        if (si == i && j <= sj) continue;
                        if (isOk(cp, i, j, count))
                            cp.push_back({ i, j });
                    }
                if (cp.size() == m)
                    return count;
            }
        }
        count--;
    }
    return count;
}

int solution(int n, int m, vector<vector<int>> timetable) {
    int maxM = 0;
    int t[1321] {0,};

    for (int i = 0; i < timetable.size(); i++) {
        for (int j = timetable[i][0]; j <= timetable[i][1]; j++) {
            t[j]++;
            maxM = max(maxM, t[j]);
        }
    }
    return maxM <= 1 ? 0 : getMinimumDist(n, maxM);
}