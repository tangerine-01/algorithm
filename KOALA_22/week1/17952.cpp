#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, cmd;
stack<pair<int, int>> problem;
int score;

void getScore();

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int l, m, r;
        cin >> l;
        if (l) {
            cin >> m >> r;
            problem.push({m, r});
        }
        if (!problem.empty()) getScore();
    }

    cout << score;

    return 0;
}

void getScore() {
    problem.top().second -= 1;

    if (problem.top().second == 0) {
        score += problem.top().first;
        problem.pop();
    }

    return ;
}