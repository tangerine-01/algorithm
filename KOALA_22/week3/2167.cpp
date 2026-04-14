#include <iostream>

using namespace std;

int N, M, K;
int arr[301][301] = {0};
pair<int, int> l, r;
int answer;

void getPS();
void getAnswer();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    getPS();

    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> l.first >> l.second >> r.first >> r.second;
        answer = 0;

        getAnswer();
    }

    return 0;
}

void getPS() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp
                        + arr[i - 1][j]
                        + arr[i][j - 1] 
                        - arr[i - 1][j - 1];
        }
    }
    
    return ;
}

void getAnswer() {
    answer = arr[r.first][r.second]
                - arr[l.first - 1][r.second]
                - arr[r.first][l.second - 1]
                + arr[l.first - 1][l.second - 1];
    cout << answer << '\n';

    return ;
}