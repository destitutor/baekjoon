// 문제에 이상이 있어서 보류함
#include <regex>
#include <bits/stdc++.h>
using namespace std;

vector<string> rsearch(string str, const string& pattern) {
    regex rx(pattern, regex_constants::icase);
    vector<string> results;
    smatch matches;
    while (regex_search(str, matches, rx)) {
        results.push_back(matches[1]);
        str = matches.suffix();
    }
    return results;
}

int solution(string word, vector<string> pages) {
    vector<string> urls;
    map<string, pair<int, int>> maps;
    map<string, vector<string>> linkScores;
    double answer = 0, maxScore = 0;
    for (auto& page : pages) {
        auto sites = rsearch(page, "(?:content|href)=\"https://(.*?)\"");
        auto body = rsearch(page, R"(<body>([\s\S]*?)</body>)")[0];
        auto words = rsearch(body, "(?:[^a-zA-Z]|^)(" + word + ")(?:[^a-zA-Z]|$)");
        urls.push_back(sites[0]);
        maps[sites[0]] = { words.size(), sites.size() - 1 };
        for (int i = 1; i < sites.size(); i++)
            linkScores[sites[i]].push_back(sites[0]);
    }

    for (int i = 0; i < urls.size(); i++) {
        double score = maps[urls[i]].first;
        for (int j = 0; j < linkScores[urls[i]].size(); j++)
            score += maps[linkScores[urls[i]][j]].first / (double)maps[linkScores[urls[i]][j]].second;
        if (maxScore < score) {
            maxScore = score;
            answer = i;
        }
    }
    return answer;
}