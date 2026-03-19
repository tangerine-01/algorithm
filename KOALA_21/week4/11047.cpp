#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> coin;
    int N, money, count = 0;

    cin >> N >> money;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        coin.push_back(temp);
    }

    sort(coin.begin(), coin.end(), [](int a, int b){return a > b;});

    for (int i = 0; i < N; i++) {
        while (money >= coin[i]) {
            money -= coin[i];
            count++;
        }
    }

    cout << count;

    return 0;
}