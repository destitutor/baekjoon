#include <bits/stdc++.h>
using namespace std;

bool visited[1000001];

vector<int> solution(string s) {
    vector<int> answers;
    vector<vector<int>> sets;

    string temp = "";
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') {
            sets.push_back(vector<int>());
        } else if (s[i] >= '0' && s[i] <= '9') {// 숫자가 이어지는 경우
            temp += s[i];
        }
                
        if (s[i + 1] == ',' || s[i + 1] == '}') { // 숫자가 끝나는 경우
            sets.back().push_back(stoi(temp));
            temp = "";
        } 
    }
    
    sort(sets.begin(), sets.end(), [](auto& v1, auto& v2) {
        return v1.size() < v2.size();
    });

    for (int i = 0; i < sets.size(); i++) {
        for (int j = 0; j < sets[i].size(); j++) {
            if (!visited[sets[i][j]]) {
                visited[sets[i][j]] = true;
                answers.push_back(sets[i][j]);
            }
        }
    }
    return answers;
}