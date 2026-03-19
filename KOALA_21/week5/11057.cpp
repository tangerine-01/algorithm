#include <iostream>
#include <string.h>

using namespace std;

int n;
int DP[1001][10];

int dp(int N, int num);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(DP, -1, sizeof(DP));

    cin >> n;

    int answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer += dp(1, i);
        answer %= 10007;
    }

    cout << answer;

    return 0;
}

int dp(int N, int num) {
    if (N == n) return 1;

    if (DP[N][num] != -1) return DP[N][num];

    DP[N][num] = 0;

    for (int i = num; i <= 9; i++) {
        DP[N][num] += dp(N + 1, i);
        DP[N][num] %= 10007;
    }
    
    return DP[N][num];
}