#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

#define MAX_TRAIN 100000
vector<int> trains(MAX_TRAIN, 0);

int main() {
    fastio;

    int N, M;
    cin >> N >> M;

    int c, s, d;
    for (int i = 0; i < M; i++) {
        cin >> c >> s;
        s--;

        if (c == 1) { // s번째 기차의 d번 좌석에 사람을 태우기
            cin >> d;
            trains[s] |= (1 << (d - 1));
        } else if (c == 2) { // s번째 기차의 d번 좌석에 있는 사람을 하차시키기
            cin >> d;
            trains[s] &= ~(1 << (d - 1));
        } else if (c == 3) { // s번째 기차에 앉아있는 승객들이 모두 한 칸씩 뒤로감
            trains[s] <<= 1;
            trains[s] &= (1 << 20) - 1;
        } else if (c == 4) { // s번째 기차에 앉아있는 승객들이 모두 한 칸씩 앞으로 감
            trains[s] >>= 1;
        }
    }

    set<int> sets;
    for (int i = 0; i < N; i++)
        sets.insert(trains[i]);
    cout << sets.size() << '\n';
}