#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int num);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    long long cnt = 0;
    vector<int> arr;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        int temp;
        temp = arr[i] - (i + 1);

        cnt += abs(temp);
    }

    cout << cnt;

    return 0;
}

int abs(int num) {
    if (num < 0) return -1 * num;
    return num;
}