#include <bits/stdc++.h>
using namespace std;

int answer = 9;

void dfs(int N, int number, int count, int currentNum) {
    if (count > 8)
        return;
    if (currentNum == number) {
        answer = min(answer, count);
    } else {
        int temp = 0;
        for (int i = 0; i < 9 - count; i++) {
            temp = temp * 10 + N;

            dfs(N, number, count + i + 1, currentNum + temp);
            dfs(N, number, count + i + 1, currentNum - temp);
            dfs(N, number, count + i + 1, currentNum * temp);
            dfs(N, number, count + i + 1, currentNum / temp);
        }
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    return answer == 9 ? -1 : answer;
}