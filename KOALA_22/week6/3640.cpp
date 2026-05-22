#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 200001;

int main() {
    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << 0;
        return 0;
    }

    vector<int> dist(MAX, -1);
    queue<int> q;

    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int next[3] = {x - 1, x + 1, 2 * x};

        for (int nx : next) {
            if (nx < 0 || nx >= MAX) continue;
            if (dist[nx] != -1) continue;

            dist[nx] = dist[x] + 1;

            if (nx == K) {
                cout << dist[nx];
                return 0;
            }

            q.push(nx);
        }
    }

    return 0;
}