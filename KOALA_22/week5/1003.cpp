#include <iostream>

using namespace std;

int zero_dp[41];
int one_dp[41];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    zero_dp[0] = 1; one_dp[0] = 0;
    zero_dp[1] = 0; one_dp[1] = 1;

    for (int i = 2; i <= 40; i++) {
        zero_dp[i] = zero_dp[i - 1] + zero_dp[i - 2];
        one_dp[i] = one_dp[i - 1] + one_dp[i - 2];
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << zero_dp[N] << " " << one_dp[N] << "\n";
    }

    return 0;
}