#include <bits/stdc++.h>
using namespace std;

int MOD = 20170805;  // 나머지 연산에 쓰이는 수

#define MAX_SIZE 500 + 1
// [0]: (i, j) 위치에서 오른쪽으로 갈 수 있는 경우의 수
// [1]: (i, j) 위치에서 아래쪽으로 갈 수 있는 경우의 수
int d[2][MAX_SIZE][MAX_SIZE];

int solution(int m, int n, vector<vector<int>> city_map) {
    fill(d[0][0], d[2][0], 0);
    // 첫 위치에서는 아래쪽이나 오른쪽으로 갈 수 있는 한 가지의 경우에서 출발한다.
    d[0][1][1] = d[1][1][1] = 1;
    
    for (int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // 0인 경우 왼쪽이나 위쪽에서 오는 경우를 더하면 된다.
            if (city_map[i-1][j-1] == 0){
                d[0][i][j] = (d[0][i][j] + d[0][i][j-1] + d[1][i-1][j]) % MOD;
                d[1][i][j] = (d[1][i][j] + d[0][i][j-1] + d[1][i-1][j]) % MOD;
            }
            // 2인 경우 왼쪽에서 오는 차량만 지나갈 수 있다.
            else if (city_map[i-1][j-1] == 2) {
                d[0][i][j] = d[0][i][j-1];
                d[1][i][j] = d[1][i-1][j];
            }
        }
    }
    
    // 목적지까지 갈 수 있는 경우의 수는 왼쪽에서 오는 경우와 위쪽에서 오는 경우를 더한 것이다.
    return (d[0][m][n-1] + d[1][m-1][n]) % MOD;
}