#include <iostream>
#include <vector>

using namespace std;

int arr[100001] = {0};

int getSum();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    
    cin >> N >> M;
 
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp + arr[i - 1];
    }

    for (int i = 0; i < M; i++) {
        cout << getSum() << '\n';
    }
 
    return 0;
}

int getSum() {
    int i, j;
    cin >> i >> j;

    return arr[j] - arr[i - 1];
}













/* 합 더하는 게 많음 -> 더하기를 최적화 해볼까..?
누적합 쓰기. 그러면 
*/