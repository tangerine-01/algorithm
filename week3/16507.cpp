#include <iostream>

using namespace std;

int arr[1001][1001] = {0};

int getAnswer();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C, Q;

    cin >> R >> C >> Q;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << getAnswer() << '\n';
    }

    return 0;
}

int getAnswer() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    return (arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1));
}