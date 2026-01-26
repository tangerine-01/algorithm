#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    int maxSize = 0;
    vector<int> arr;

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        maxSize = max(maxSize, temp);
    }

    int left = 1;
    int right = maxSize;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;

        for (auto it:arr) {
            count += it / mid;
        }

        if (count >= M) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << answer;

    return 0;
}