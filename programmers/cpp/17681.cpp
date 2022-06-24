#include <bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
        int aRow = arr1[i], bRow = arr2[i];
        for (int j = 0; j < n; j++)
            if (((aRow & (1 << j)) != 0) || ((bRow & (1 << j)) != 0))
                answer[i][n - j - 1] = '#';
    }
    return answer;
}