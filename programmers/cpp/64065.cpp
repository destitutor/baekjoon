#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> answer;
    string temp;
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{')
            answer.push_back(vector<int>());
        if (s[i] >= '0' && s[i] <= '9')
            temp += s[i];
        if (s[i] == ',' || s[i] == '}') {
            if (!temp.empty()) {
                answer.back().push_back(stoi(temp));
                temp = "";
            }
        }
    }
    sort(answer.begin(), answer.end(), [](auto v1, auto v2) {
        return v1.size() < v2.size(); });
    vector<int> an;
    for (int i = 0; i < answer.size(); i++)
        for (int j = 0; j < answer[i].size(); j++)
            if (find(an.begin(), an.end(), answer[i][j]) == an.end())
                an.push_back(answer[i][j]);
    return an;
}