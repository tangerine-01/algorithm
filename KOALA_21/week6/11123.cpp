#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char arr[101][101];
bool check[101][101];

int main() {
    cin >> T;
    while (T--) {
        int H, W;
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> arr[i][j];
            }
        }
        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (check[i][j] == false && arr[i][j] == '#') {
                    check[i][j] = true;
                    count++;
                    q.push({i, j});
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                                if (arr[nx][ny] == '#') {
                                    if (!check[nx][ny]) {
                                        check[nx][ny] = true;
                                        q.push({nx, ny});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << count << "\n";
        memset(arr, false, sizeof(arr));
        memset(check, false, sizeof(check));
    }
}
