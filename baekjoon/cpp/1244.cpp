#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

#define MAX_SWITCH 100
int switches[MAX_SWITCH + 1];

int main() {
    fastio;
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> switches[i];
    
    int numOfStudents;
    cin >> numOfStudents;

    int gender, num;
    for (int i = 0; i < numOfStudents; i++) {
        cin >> gender >> num;

        if (gender == 1) { // 남학생은 1, 여학생은 2
            // 남학생은 스위치 번호가 자기가 받은 수의 배수이면 그 스위치의 상태를 바꿈
            for (int j = num; j <= N; j += num)
                switches[j] = !switches[j];
        } else if (gender == 2) {
            // 여학생은 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로
            // 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간을 찾아서 그 구간에 속한 스위치의 상태를 모두 바꿈
            for (int l = num, r = num; l > 0 && r <= N; l--, r++) {
                if (switches[l] == switches[r]) {
                    switches[l] = switches[r] = !switches[l];
                } else break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << switches[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
}