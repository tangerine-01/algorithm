#include <iostream>

using namespace std;

int N, M;
int arr[1025][1025];
int prefix_sum[1025][1025];
pair<int, int> l, r;
int answer;

void getArr();
void getPrefixSum();
void getAnswer();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    getArr();
    getPrefixSum();

    for (int i = 0; i < M; i++) {
        cin >> l.first >> l.second >> r.first >> r.second;
        answer = 0;

        getAnswer();
    }

    return 0;
}

void getArr() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    return ;
}

void getPrefixSum() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix_sum[i][j] = arr[i][j]
                                + prefix_sum[i - 1][j]
                                + prefix_sum[i][j - 1] 
                                - prefix_sum[i - 1][j - 1];
        }
    }

    return ;
}

void getAnswer() {
    answer = prefix_sum[r.first][r.second]
                - prefix_sum[l.first - 1][r.second]
                - prefix_sum[r.first][l.second - 1]
                + prefix_sum[l.first - 1][l.second - 1];
    cout << answer << '\n';

    return ;
}