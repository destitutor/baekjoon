#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        if (first >= K) return answer;

        int second = pq.top(); pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    return pq.top() >= K ? answer : -1;
}