#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
};

void MyQueue::push(int data) {
    s1.push(data);
}

int MyQueue::pop() {
    if (s1.empty() && s2.empty()) {
        cout << "큐가 비어있습니다.\n";
        return -1;
    }

    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int front = s2.top();
    s2.pop();
    return front;
}

int main() {
    fastio;

    MyQueue q;

    q.push(3);
    q.push(4);
    cout << "pop(): " << q.pop() << "\n";
    cout << "pop(): " << q.pop() << "\n";

    q.push(5);
    q.push(6);
    cout << "pop(): " << q.pop() << "\n";

    q.push(7);
    q.push(8);
    cout << "pop(): " << q.pop() << "\n";
    cout << "pop(): " << q.pop() << "\n";
    cout << "pop(): " << q.pop() << "\n";
}