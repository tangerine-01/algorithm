#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
// 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽

int dxx[8]={0,-1,-1, -1, 0, 1, 1, 1};
int dyy[8]={1, 1, 0, -1, -1, -1, 0, 1};

int N;
string A;

bool kuung();
bool isBul();
void turnOn(int r,int c);
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

Ari::Ari(){
    this -> x = 0;
    this -> y = 0;
    this -> direction = 2;
}

void Ari::front() {
    x += dx[direction];
    y += dy[direction];
    return ;
}

void Ari::turn(char cmd) {
    if (cmd == 'R') {
        direction = (direction + 1) % 4;
    } else if (cmd == 'L') {
        direction = (direction + 3) % 4;
    }
}

inline bool Ari::inRange() {
    return 0 <= x + dx[direction]
        && x + dx[direction] < N
        && 0 <= y + dy[direction]
        && y + dy[direction] < N;
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
    this -> x = x;
    this -> y = y;
    this -> direction = 2;
}

inline bool Zombi::inRange() {
    return 0 <= this -> x + dx[direction]
        && this -> x + dx[direction] < N
        && 0 <= this -> y + dy[direction]
        && this -> y + dy[direction] < N;
}

void Zombi::move() {
    if (!inRange()) {
        direction=(direction+2)%4;
        return ;
    }
    this -> x += dx[direction];
    this -> y += dy[direction];
    return ;
}

Ari ari;
vector<Zombi> zombis;
char Buls[15][15] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> A;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            char temp;
            cin >> temp;
            if (temp == 'Z') {
                Zombi z(j, i);
                zombis.push_back(z);
            }
            if (temp == 'S') {
                Buls[i][j] = temp;
            }
        }
    }

    for (int i = 0; i < A.size(); i++) {

        // 1️⃣ 아리 행동
        if (A[i] == 'F') {
            if (ari.inRange()) {
                ari.front();
            }
        } else {
            ari.turn(A[i]);
        }

        // 3️⃣ 좀비 이동
        for (Zombi &z : zombis) {
            z.move();
        }

        // 4️⃣ 좀비 이동 후 판정
        if (kuung() && !isBul()) {
            cout << "Aaaaaah!";
            return 0;
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

bool isBul() {
    if(Buls[ari.y][ari.x]=='S'){
        turnOn(ari.y,ari.x);
        return true;
    }
    if(Buls[ari.y][ari.x] == 's'){
        return true;
    }
    return false;
}

void turnOn(int r,int c){
    for(int i=0;i<8;i++){
        int nr=r+dyy[i],nc=c+dxx[i];
        if(!inRange(nr,nc)) continue;
        if(Buls[nr][nc]=='S') continue;
        Buls[nr][nc]='s';
    }
}

bool inRange(int r, int c) {
    return 0<=r&&r<N&&0<=c&&c<N;
}