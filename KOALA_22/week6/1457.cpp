#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int map[101][101];
int visited[101][101];
vector<int> cntArr;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int M, N, K, cnt;

void dfs(int r, int c);
void paintBox();
bool inRange(int r, int c);
bool isVisited(int r, int c);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        paintBox();
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;
                dfs(i, j);
                cntArr.push_back(cnt);
                ans++;
            }
        }
    }

    sort(cntArr.begin(), cntArr.end());
    cout << ans << '\n';

    for (int i = 0; i < cntArr.size(); i++) cout << cntArr[i] << ' ';

    return 0;
}

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (inRange(nr, nc)) continue;

        if (isVisited(nr, nc)) {
            visited[nr][nc] = 1;
            cnt ++;
            dfs(nr, nc);
        }
    }
    return ;
}

void paintBox() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int r = b; r < d; r++) {
        for (int l = a; l < c; l++) map[r][l] = true;
    } 
    return ;
}

bool inRange(int r, int c) {
    return r >= M || r < 0 || c >= N || c < 0;
}

bool isVisited(int r, int c) {
    return visited[r][c] == 0 && map[r][c] == 0;
}