#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

int main() {
    fastio;
    
    string s;
    cin >> s;

    vector<string> ducks;
    for (int i = 0; i < s.length(); i++) {
        bool isSuccess = false;
        for (int j = 0; j < ducks.size(); j++) {
            bool isMatch = false;
            switch (s[i]) {
                case 'q': isMatch = ducks[j].back() == 'k'; break;
                case 'u': isMatch = ducks[j].back() == 'q'; break;
                case 'a': isMatch = ducks[j].back() == 'u'; break;
                case 'c': isMatch = ducks[j].back() == 'a'; break;
                case 'k': isMatch = ducks[j].back() == 'c'; break;
            }
            if (isMatch) {
                ducks[j] += s[i];
                isSuccess = true;
                break;
            }
        }
        if (ducks.size() != 0) {
            if (!isSuccess) {
                if (s[i] == 'q') ducks.push_back("q");
                else { cout << "-1\n"; return 0; }
            }
        } else {
            if (s[i] == 'q') ducks.push_back("q");
            else { cout << "-1\n"; return 0; }
        }
    }

    bool isSuccess = true;
    for (int i = 0; i < ducks.size(); i++) {
        if (ducks[i].length() % 5 != 0) {
            isSuccess = false;
            break;
        }
    }
    if (isSuccess) cout << ducks.size() << '\n';
    else cout << "-1\n";
}