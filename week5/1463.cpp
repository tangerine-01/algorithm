#include <iostream>
#include <string.h>

using namespace std;

int N;
int DP[1000001];

int dp(int X);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(DP, -1, sizeof(DP));

    cin >> N;

    cout << dp(N);
    
    return 0;
}

int dp(int X) {
    if (X == 1) return 0;

    if (DP[X] != -1) return DP[X];

    DP[X] = dp(X - 1) + 1;
    if (X % 3 == 0) {
        int temp = dp(X / 3) + 1;
        DP[X] = min(temp, DP[X]);
    }
    if (X % 2 == 0) {
        int temp = dp(X / 2) + 1;
        DP[X] = min(temp, DP[X]);
    }

    return DP[X];
}