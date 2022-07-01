#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0)
            answer.push_back(numbers[i] + 1);
        else {
            long long zb = (numbers[i] + 1) & (-numbers[i]);
            answer.push_back((numbers[i] | zb) & (~zb >> 1));
        }
    }
    return answer;
}