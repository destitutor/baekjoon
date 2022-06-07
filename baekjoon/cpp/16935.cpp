#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

void invertTopAndBottom(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size() / 2; i++)
        for (int j = 0; j < vec[0].size(); j++)
            swap(vec[i][j], vec[vec.size() - i - 1][j]);
}

void invertLeftAndRight(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec[i].size() / 2; j++)
            swap(vec[i][j], vec[i][vec[i].size() - j - 1]);
}

void rotateRight(vector<vector<int>>& vec) {
    vector<vector<int>> tmp(vec[0].size(), vector<int>(vec.size()));
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec[i].size(); j++)
            tmp[j][vec.size() - i - 1] = vec[i][j];
    vec = tmp;
}

void rotateLeft(vector<vector<int>>& vec) {
    vector<vector<int>> tmp(vec[0].size(), vector<int>(vec.size()));
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec[i].size(); j++)
            tmp[vec[0].size() - j - 1][i] = vec[i][j];
    vec = tmp;
}

void moveGroup(vector<vector<int>>& vec, int si, int sj, int r, int c, vector<vector<int>>& dest, int di, int dj) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dest[di + i][dj + j] = vec[si + i][sj + j];
}

void rotateRightGroup(vector<vector<int>>& vec) {
    vector<vector<int>> tmp(vec.size(), vector<int>(vec[0].size()));
    int groupWidth = vec[0].size() / 2;
    int groupHeight = vec.size() / 2;
    moveGroup(vec, 0, 0, groupHeight, groupWidth, tmp, 0, groupWidth);
    moveGroup(vec, 0, groupWidth, groupHeight, groupWidth, tmp, groupHeight, groupWidth);
    moveGroup(vec, groupHeight, groupWidth, groupHeight, groupWidth, tmp, groupHeight, 0);
    moveGroup(vec, groupHeight, 0, groupHeight, groupWidth, tmp, 0, 0);
    vec = tmp;
}

void rotateLeftGroup(vector<vector<int>>& vec) {
    vector<vector<int>> tmp(vec.size(), vector<int>(vec[0].size()));
    int groupWidth = vec[0].size() / 2;
    int groupHeight = vec.size() / 2;
    moveGroup(vec, 0, 0, groupHeight, groupWidth, tmp, groupHeight, 0);
    moveGroup(vec, 0, groupWidth, groupHeight, groupWidth, tmp, 0, 0);
    moveGroup(vec, groupHeight, groupWidth, groupHeight, groupWidth, tmp, 0, groupWidth);
    moveGroup(vec, groupHeight, 0, groupHeight, groupWidth, tmp, groupHeight, groupWidth);
    vec = tmp;
}

void printArray(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastio;

    int n, m, r;
    cin >> n >> m >> r;
    
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> vec[i][j];

    for (int i = 0; i < r; i++) {
        int op;
        cin >> op;
        if (op == 1) invertTopAndBottom(vec);
        else if (op == 2) invertLeftAndRight(vec);
        else if (op == 3) rotateRight(vec);
        else if (op == 4) rotateLeft(vec);
        else if (op == 5) rotateRightGroup(vec);
        else if (op == 6) rotateLeftGroup(vec);
    }
    printArray(vec);
}