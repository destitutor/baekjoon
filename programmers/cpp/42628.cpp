#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    int count = 0;
    priority_queue<int, vector<int>> mapq;
    priority_queue<int, vector<int>, greater<int>> mipq;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            int d = stoi(operations[i].substr(2));
            mapq.push(d);
            mipq.push(d);
            count++;
        } else if (count > 0) {
            if (operations[i][2] == '-') mipq.pop();
            else mapq.pop();
            count--;
        }
        if (count == 0) {
            while (!mapq.empty()) mapq.pop();
            while (!mipq.empty()) mipq.pop();
        }
    }

    if (count <= 0) return {0, 0};
    else return {mapq.top(), mipq.top()};
}