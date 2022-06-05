#include <bits/stdc++.h>
using namespace std;

int getLength(const string& s, double start) {
	int left = floor(start), right = ceil(start);
	int length = left == right ? 1 : s[left] == s[right] ? 2 : 0;
	while (true) {
		if (left - 1 < 0) break;
		left--;
		if (right + 1 >= s.size()) break;
		right++;
        if (s[left] != s[right]) break;
		length += 2;
	}
	return length;
}

int solution(string s) {
	int answer = 0;
	for (double i = 0; i < s.size(); i += 0.5) {
		answer = max(answer, getLength(s, i));
	}
	return answer;
}