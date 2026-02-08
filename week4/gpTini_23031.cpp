#include <iostream>
#include <vector>
using namespace std;

// 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int dxx[8] = {0,-1,-1,-1,0,1,1,1};
int dyy[8] = {1,1,0,-1,-1,-1,0,1};

int N;
string A;
char Buls[15][15] = {0};

bool inRange(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < N;
}

class Ari {
public:
    int x = 0, y = 0, dir = 2; // 시작: (0,0), 아래
    void turn(char c) {
        if (c == 'R') dir = (dir + 1) % 4;
        else dir = (dir + 3) % 4;
    }
    bool canMove() {
        int nx = x + dx[dir], ny = y + dy[dir];
        return inRange(ny, nx);
    }
    void move() {
        x += dx[dir];
        y += dy[dir];
    }
};

class Zombi {
public:
    int x, y, dir = 2;
    Zombi(int x, int y): x(x), y(y) {}
    bool canMove() {
        int nx = x + dx[dir], ny = y + dy[dir];
        return inRange(ny, nx);
    }
    void move() {
        if (!canMove()) dir = (dir + 2) % 4;
        x += dx[dir];
        y += dy[dir];
    }
};

Ari ari;
vector<Zombi> zombis;

void turnOn(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int nr = r + dyy[i], nc = c + dxx[i];
        if (!inRange(nr, nc)) continue;
        if (Buls[nr][nc] == 'S') continue;
        Buls[nr][nc] = 's';
    }
}

bool isBul() {
    if (Buls[ari.y][ari.x] == 'S') {
        Buls[ari.y][ari.x] = 's';
        turnOn(ari.y, ari.x);
        return true;
    }
    return Buls[ari.y][ari.x] == 's';
}

bool kuung() {
    for (auto &z : zombis)
        if (z.x == ari.x && z.y == ari.y)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char t; cin >> t;
            if (t == 'Z') zombis.emplace_back(j, i);
            if (t == 'S') Buls[i][j] = 'S';
        }
    }

    // 🔴 시작 위치 판정
    if (kuung() && !isBul()) {
        cout << "Aaaaaah!";
        return 0;
    }

    for (char cmd : A) {
        // 1. 아리 행동
        if (cmd == 'F') {
            if (ari.canMove()) ari.move();
        } else {
            ari.turn(cmd);
        }

        // 2. 아리 이동 직후 판정
        if (kuung() && !isBul()) {
            cout << "Aaaaaah!";
            return 0;
        }

        // 3. 좀비 이동
        for (auto &z : zombis) z.move();

        // 4. 좀비 이동 후 판정
        if (kuung() && !isBul()) {
            cout << "Aaaaaah!";
            return 0;
        }
    }

    cout << "Phew...";
    return 0;
}
