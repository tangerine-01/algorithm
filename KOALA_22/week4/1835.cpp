#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> dq;

void getOrder(int i);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = N; i >= 1; i--) {
        dq.push_front(i);

        getOrder(i);
    }

    for (int num : dq) {
        cout << num << " ";
    }

    return 0;
}

void getOrder(int i) {
    for (int j = 0; j < i; j++) {
        int b = dq.back();
        dq.pop_back();
        dq.push_front(b);
    }

    return;
}