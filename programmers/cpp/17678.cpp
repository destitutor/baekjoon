#include <bits/stdc++.h>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    sort(timetable.begin(), timetable.end());
    queue<string> q;
    for (auto& time : timetable)
        q.push(time);

    map<int, vector<int>> dict;
    int currentTimes = 9 * 60;
    for (int i = 0; i < n; i++) { // 배차
        dict[currentTimes] = vector<int>();
        for (int k = 0; k < m && !q.empty(); k++) { // m명 태우고 감
            string time = q.front();
            int arrivedTimes = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));

            if (currentTimes >= arrivedTimes) {
                q.pop();
                dict[currentTimes].push_back(arrivedTimes);
            }
        }
        currentTimes += t;
    }

    int ans = -1;
    for (auto& entry : dict) {
        if (entry.second.size() < m) // 빈 자리가 있음
            ans = entry.first;
        else if (entry.second.front() == entry.second.back()) // 빈 자리가 없고 끼어들 여지도 없음
            ans = entry.second.front() - 1;
        else // 빈 자리는 없으나 끼어들 여지는 있음
            ans = entry.second.back() - 1;
    }

    char buffer[10];
    sprintf(buffer, "%02d:%02d", ans / 60, ans % 60);
    return buffer;
}