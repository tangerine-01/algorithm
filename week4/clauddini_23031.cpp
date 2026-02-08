#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
// 8방향: 0=아래, 1=좌하, 2=왼쪽, 3=좌상, 4=위, 5=우상, 6=오른쪽, 7=우하

int N;
string A;

bool kuung();
bool isSafe();
void turnOn(int r, int c);
bool inRange(int r, int c);

class Ari {
public:
    int x;
    int y;
    int direction;
    Ari();
    void front();
    inline bool inRange();
    void turn(char cmd);
};

Ari::Ari() {
    this->x = 1;
    this->y = 1;
    this->direction = 0;  // 아래 방향
}

void Ari::front() {
    x += dx[direction];
    y += dy[direction];
}

void Ari::turn(char cmd) {
    if (cmd == 'R') {
        direction = (direction + 2) % 8;
    } else if (cmd == 'L') {
        direction = (direction + 6) % 8;
    }
}

inline bool Ari::inRange() {
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    return 1 <= nx && nx <= N && 1 <= ny && ny <= N;
}

class Zombi {
public:
    int x;
    int y;
    int direction;
    Zombi(int x, int y);
    inline bool inRange();
    void move();
};

Zombi::Zombi(int x, int y) {
    this->x = x;
    this->y = y;
    this->direction = 0;  // 아래 방향
}

inline bool Zombi::inRange() {
    int nx = this->x + dx[direction];
    int ny = this->y + dy[direction];
    return 1 <= nx && nx <= N && 1 <= ny && ny <= N;
}

void Zombi::move() {
    if (!inRange()) {
        direction = (direction + 4) % 8;  // 반대 방향
        return;
    }
    this->x += dx[direction];
    this->y += dy[direction];
}

Ari ari;
vector<Zombi> zombis;
char safeZone[16][16] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> A;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char temp;
            cin >> temp;
            if (temp == 'Z') {
                Zombi z(j, i);  // x=열, y=행
                zombis.push_back(z);
            }
            if (temp == 'S') {
                safeZone[i][j] = temp;
            }
        }
    }

    for (int i = 0; i < A.size(); i++) {

        // 1️⃣ 아리 행동
        if (A[i] == 'F') {
            if (ari.inRange()) {
                ari.front();
            }
            
            // 2️⃣ 스위치 체크 및 켜기
            if (safeZone[ari.y][ari.x]) {
                if (safeZone[ari.y][ari.x] == 'S') {
                    turnOn(ari.y, ari.x);
                }
                // 안전지대면 좀비 체크 안 하고 좀비 이동으로
            } else {
                // 안전지대 아니면 좀비와 충돌 체크
                if (kuung()) {
                    cout << "Aaaaaah!";
                    return 0;
                }
            }
        } else {
            ari.turn(A[i]);
        }

        // 3️⃣ 좀비 이동
        for (Zombi &z : zombis) {
            z.move();
        }

        // 4️⃣ 좀비 이동 후 판정
        if (!safeZone[ari.y][ari.x]) {
            if (kuung()) {
                cout << "Aaaaaah!";
                return 0;
            }
        }
    }

    cout << "Phew...";
    return 0;
}

bool kuung() {
    for (Zombi &z : zombis) {
        if (z.x == ari.x && z.y == ari.y) return true;
    }
    return false;
}

void turnOn(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if (!inRange(nr, nc)) continue;
        if (safeZone[nr][nc] == 'S') continue;
        safeZone[nr][nc] = 's';
    }
}

bool inRange(int r, int c) {
    return 1 <= r && r <= N && 1 <= c && c <= N;
}