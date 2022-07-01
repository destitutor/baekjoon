#include <bits/stdc++.h>
using namespace std;

int arr[60001] = {0, 1, 2, };

int solution(int n) {
	for (int i = 3; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007;
	return arr[n];
}