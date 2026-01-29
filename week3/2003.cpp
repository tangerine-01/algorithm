#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    vector<int> arr;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
    
        arr.push_back(temp);
    }

    int start = -1, end = -1;
    int sum = 0, count = 0;

    while(start <= end && end < N) {
        if (sum < M) sum += arr[++end];
        else if (sum > M) sum -= arr[++start];
        else {
            count++;
            sum += arr[++end];
        }
    }

    cout << count;

    return 0;
}