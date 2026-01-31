#include <iostream>
#include <vector>

using namespace std;

int T, N;
int getTestcase();
int getSum(vector<int> &arr);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << getTestcase() << '\n';
    }
}

int getTestcase() {
    vector<int> arr;

    arr.push_back(0);

    for (int i = 1; i <= N; i++) {
            int temp;

            cin >> temp;

            arr.push_back(temp);
    }
    
    for (int i = 1; i <= N; i++) arr[i] = arr[i] + arr[i - 1];

    return getSum(arr);
}

int getSum(vector<int> &arr) {
    int temp = 0;
    int numMax = arr[1];
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            temp = arr[j] - arr[i];
            numMax = max(numMax, temp);
        }
    }
    return numMax;
}

