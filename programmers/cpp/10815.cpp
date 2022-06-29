#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

int arr[500000];

int search(int a, int n) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] > a) right = mid - 1;
        else if (arr[mid] < a) left = mid + 1;
        else return 1;
    }
    return 0;
}

int main() {
    fastio;
    
    int n, m, t;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    cin >> m;
    while (m--) {
        cin >> t;
        cout << search(t, n) << ' ';
    }
}