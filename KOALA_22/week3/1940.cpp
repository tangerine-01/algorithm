#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), less<int>());

    int l = 0;
    int r = N - 1;
    int cnt = 0;

    while (l < r) {
        int temp = arr[l] + arr[r];

        if (temp < M) l++;
        else if (temp > M) r--;
        else {
            cnt++;
            l++;
            r--;
        }
    }

    cout << cnt;

    return 0;
}