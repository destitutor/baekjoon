#include <bits/stdc++.h>
using namespace std;

string compress(string str, int stride) {
    int lastIndex = 0;
    string answer;

    for (int i = 0; i < str.size() - stride; i++) {
        int count = 0, j = 0;
        string cur = str.substr(i, stride);

        for (j = i + stride; j < str.size() - stride; j += stride) {
            string par = str.substr(j, stride);
            if (cur == par) count++;
            else break;
        }

        if (count == 0) {
            lastIndex = i + 1;
            answer += str[i];
        } else {
            answer += to_string(count + 1) + cur;
            i += count * stride - 1;
            lastIndex = i + 1;
        }
    }

    if (lastIndex < str.size())
        answer += str.substr(lastIndex);
    return answer;
}

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.size() / 2; i++) {
        string result = compress(s, i);
        answer = min(answer, (int)result.size());
    }
    return answer;
}