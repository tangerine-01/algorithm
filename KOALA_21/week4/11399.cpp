#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    long long cnt = 0;
    long long answer = 0;
    vector<int> arr;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i < N; i++) {
        cnt += arr[i];
        answer += cnt;
    }

    answer += N * arr[0];
    
    cout << answer;

    return 0;
}