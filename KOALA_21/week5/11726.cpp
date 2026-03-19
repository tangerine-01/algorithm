#include <iostream>
#include <string.h>

using namespace std;

int n;
int DP[1001];

int dp(int k);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(DP, -1, sizeof(DP));

    cin >> n;                                              

    cout << dp(n);
    
    return 0;
}

int dp(int k) {
    if (k == 1) return 1;
    if (k == 2) return 2;
    if (DP[k] != -1) return DP[k];
    DP[k] = (dp(k - 1) + dp(k - 2)) % 10007;
    return DP[k];
}