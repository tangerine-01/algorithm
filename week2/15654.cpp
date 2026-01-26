#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int picked[8];
bool visited[10] = {0};

void recursive(int len);

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    recursive(0);

    return 0;
}

void recursive(int len) {
    if (len == M) {
        for (int i = 0; i < M; i++) {
            cout << picked[i] << ' ';
        }
        cout << '\n';

        return ;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        picked[len] = arr[i];

        visited[i] = true;
        recursive(len + 1);
        visited[i] = false;
    }
    return ;
}