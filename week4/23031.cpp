// 나중에 코드 개선 필요 ^^..

#include <iostream>
#include <vector>

using namespace std;

bool kuung();
int isS();
int isBull();
int ariFront();
int ariTurn(int i);
inline bool inRange(int r, int c);

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

class S {
    public:
        int x, y;
        S(int x, int y);
};

S::S(int x, int y) {
    this -> x = x;
    this -> y = y;
}

class Bull {
    public:
        int x, y;
        Bull(int x, int y);
};

Bull::Bull(int x, int y) {
    this -> x = x;
    this -> y = y;
}

class Ari {
    public:
        int x;
        int y;
        int direction;
        Ari();
        void front();
        void turn(char cmd);
};

Ari::Ari(){
    this -> x = 0;
    this -> y = 0;
    this -> direction = 0;
}

void Ari::front() {
    x += dx[direction];
    y += dy[direction];
    return ;
}

void Ari::turn(char cmd) {
    if (cmd == 'R') {
        if (direction == 0) {
            direction = 3;
            return ;
        }
        direction--;
        return ;
    }
    if (cmd == 'L') {
        if (direction == 3) {
            direction = 0;
            return ;
        }
        direction++;
        return ;
    }
}

class Zombi {
    public:
        int x;
        int y;
        int direction;
        Zombi(int x, int y);
        void move();
        void kuung();
};

Zombi::Zombi(int x, int y) {
    this -> x = x;
    this -> y = y;
    this -> direction = 0;
}

void Zombi::move() {
    if (!inRange(this -> x + dx[direction], this -> y + dy[direction])) {
        if (direction >= 2) direction -= 2;
        if (direction <= 1) direction += 2;
        return ;
    }
    this -> x += dx[direction];
    this -> y += dy[direction];
    return ;
}

int N;
string A;
Ari ari;
vector<Zombi> zombis;
vector<S> ss;
vector<Bull> bulls;
bool isKuung = false;

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
                Zombi z(i, j);
                zombis.push_back(z);
            }
            if (temp == 'S') {
                S s(i, j);
                ss.push_back(s);
            }
        }
    }
    
    for (int i = 0; i < A.size(); i++) {
        for (Zombi &z:zombis) z.move();
        if (A[i] == 'F') ariFront();
        else ariTurn(i);
    }

    if (!isKuung) cout << "Phew...";

    return 0;
}

bool kuung() {
    for (Zombi &z:zombis) {
        if ((z.x == ari.x && z.y == ari.y)){
            isKuung = true;
            return true;
        }
    }
    return false;
}

int isS() {
    for (S &s:ss) {
        if ((s.x == ari.x && s.y == ari.y)) {
            Bull a(s.x, s.y); bulls.push_back(a);
            Bull b(s.x + 1, s.y); bulls.push_back(b);
            Bull c(s.x, s.y + 1); bulls.push_back(c);
            Bull d(s.x - 1, s.y); bulls.push_back(d);
            Bull e(s.x, s.y - 1); bulls.push_back(e);
            return 1;
        }
        else return 0;
    }
    return 0;
}

int isBull() {
    for (Bull &bull:bulls) {
        if (!(bull.x == ari.x && bull.y == ari.y)) continue;
        return 0;
    }
    return 1;
}

int ariFront() {
    if (!isS()) {
        if (!isBull()) {
            ari.front();
            if (!isBull()) return 1;
            if (kuung()) cout << "Aaaaaah!";
            return 1;
        }
        if (kuung()) cout << "Aaaaaah!";
        return 1;
    }
    return 0;
}

int ariTurn(int i) {
    if (A[i] == 'R' && A[i] == 'L') {
        if (isBull()) {
            ari.turn(A[i]);
            return 0;
        }
        if (kuung()) cout << "Aaaaaah!";
        ari.turn(A[i]);
        return 0;
    }
    return -1;
}

inline bool inRange(int r, int c) {
    return 0 <= r  && r < N && 0 <= c && c < N;
}

/*
Aaaaaah!
Phew...
*/