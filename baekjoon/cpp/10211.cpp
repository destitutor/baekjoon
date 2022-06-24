#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int d[1001];

int solve(int n) {
    int sum = arr[0], answer = arr[0];

    memset(d, 0, sizeof(d));
    d[0] = arr[0];
    for (int i = 1; i < n; i++) {
        d[i] = arr[i];
        if (arr[i] + d[i - 1] > d[i])
            d[i] = arr[i] + d[i - 1];
        answer = max(answer, d[i]);
    }
    return answer;
}

int main() {
    fastio;

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(n) << '\n';
    }
}