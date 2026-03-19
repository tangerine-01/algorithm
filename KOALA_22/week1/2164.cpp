#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

void makeCards();
void game();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    makeCards();
    game();

    return 0;
}

void makeCards() {
    for (int i = 1; i <= N; i++) q.push(i);

    return ;
}

void game() {
    while (q.size() > 1) {
        q.pop();

        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}