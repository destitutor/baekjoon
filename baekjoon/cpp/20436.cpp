#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
#define DIST(a, b) (abs(a.first - b.first) + abs(a.second - b.second))

using namespace std;

char L, R;
string lboard[3] = {"qwert", "asdfg", "zxcv"};
string rboard[3] = {"     yuiop", "     hjkl", "    bnm"};

int main() {
    fastio;

    map<char, pair<int, int>> ldict; // (key, (row, column))
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < lboard[i].length(); j++)
            if (lboard[i][j] != ' ')
                ldict[lboard[i][j]] = make_pair(i, j);
    map<char, pair<int, int>> rdict; // (key, (row, column))
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < rboard[i].length(); j++)
            if (rboard[i][j] != ' ')
                rdict[rboard[i][j]] = make_pair(i, j);

    cin >> L >> R;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (ldict.count(s[i])) { // 자음
            ans += DIST(ldict[L], ldict[s[i]]);
            L = s[i];
        } else {
            ans += DIST(rdict[R], rdict[s[i]]);
            R = s[i];
        }
        ans++;
    }
    cout << ans << '\n';
}