#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    for (int i = 0; i < numbers.size(); i++)
        strs.push_back(to_string(numbers[i]));

    sort(strs.begin(), strs.end(), [](string& s1, string& s2) {
        return s1 + s2 > s2 + s1;
    });
    if (strs.front() == "0")
        return "0";
    for (int i = 0; i < strs.size(); i++)
        answer += strs[i];
    return answer;
}