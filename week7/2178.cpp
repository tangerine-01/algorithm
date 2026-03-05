#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};

char mapp[101][101];
int dist[101][101] = {0};
bool visited[101][101] = {0};

int N, M;

inline bool inRange(int r, int c);
void bfs(int r, int c);

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> mapp[i][j];
        }
    }

    bfs(1, 1);

    return 0;
}

inline bool inRange(int r, int c) {
    return 1 <= r && r <= N && 1 <= c && c <= M;
}

void bfs(int r, int c) {
    queue< pair<int, int> > q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int tr = p.first;
        int tc = p.second;

        for(int i = 0; i < 4; i++) {
            int nr = dr[i] + tr;
            int nc = dc[i] + tc;

            if (!inRange(nr, nc)) continue;
            if (mapp[nr][nc] == '0') continue;
            if (visited[nr][nc]) continue;

            dist[nr][nc] = dist[tr][tc] + 1;
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
    cout << dist[N][M] + 1;
}