#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

int val[26];

int main() {
    fastio;
    
    int n, t;
    cin >> n;

    string expr;
    cin >> expr;

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    stack<double> s;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] >= 'A' && expr[i] <= 'Z') {
            s.push(val[expr[i] - 'A']);
        } else {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            switch (expr[i]) {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
            }
        }
    }
    cout.precision(2);
    cout << fixed << s.top() << '\n';
}