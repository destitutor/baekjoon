#include <bits/stdc++.h>
using namespace std;

inline bool isLower(char a) {
    return a >= 'a' && a <= 'z';
}

vector<string> split(string str) {
    vector<string> result;
    for (int i = 0; i < str.size() - 1; i++)
        if (isLower(str[i]) && isLower(str[i + 1]))
            result.push_back(str.substr(i, 2));
    return result;
}

void toLower(string& str) {
    for (int i = 0; i < str.size(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= 32;
}

int solution(string str1, string str2) {
    int answer = 0, commonCount = 0;

    toLower(str1);
    toLower(str2);

    set<string> sets;
    map<string, string> maps;
    vector<string> temp = split(str1);
    for (int i = 0; i < temp.size(); i++) {
        sets.insert(temp[i]);
    }

    cout << str1 << '\n';

    return answer;
}