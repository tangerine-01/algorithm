#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int map[26][26];
int visited[26][26];
vector<int> cntArr;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int N, cnt;

void dfs(int r, int c);
bool inRange(int r, int c);
bool isVisited(int r, int c);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;

    cin >> N;
    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            visited[i][j] = 0;

            if (str[j] == '1') map[i][j] = 1;
            else map[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;
                dfs(i, j);
                cntArr.push_back(cnt);
                ans++;
            }
        }
    }

    sort(cntArr.begin(), cntArr.end());
    cout << ans << "\n";;

    for (int i = 0; i < cntArr.size(); i++) cout << cntArr[i] << "\n";

    return 0;
}

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (inRange(nr, nc)) continue;

        if (isVisited(nr, nc)) {
            visited[nr][nc] = 1;
            cnt += 1;
            dfs(nr, nc);
        }
    }
    return ;
}

bool inRange(int r, int c) {
    return r >= N || r < 0 || c >= N || c < 0;
}

bool isVisited(int r, int c) {
    return visited[r][c] == 0 && map[r][c] == 1;
}