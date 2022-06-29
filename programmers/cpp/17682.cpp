#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    vector<int> ans;
    regex r("([0-9]{1,2})(S|D|T)(\\*|#)?");
    smatch mr;
    while (regex_search(dartResult, mr, r)) {
        int n = stoi(mr.str(1));
        string c = mr.str(2), o = mr.str(3);

        ans.push_back(n);
        int ci = ans.size() - 1;
        
        // 보너스
        if (c == "D") ans[ci] = pow(ans[ci], 2);
        else if (c == "T") ans[ci] = pow(ans[ci], 3);

        // 옵션
        if (o == "*") {
            if (ci > 0)
                ans[ci - 1] *= 2;
            ans[ci] *= 2;
        } else if (o == "#") ans[ci] *= -1;
        dartResult = mr.suffix().str();
    }

    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
        sum += ans[i];
    return sum;
}