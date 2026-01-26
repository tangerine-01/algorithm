#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N, M;
    long long maxSize = 0;
    vector<int> arr;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        maxSize = max(maxSize, temp);
    }

    long long left = 1;
    long long right = maxSize * M;
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (auto it:arr) {
            count += mid / it;
        }

        if (count >= M) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << answer;

    return 0;
}