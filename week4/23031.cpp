// 나중에 코드 개선 필요 ^^..

#include <iostream>
#include <vector>

using namespace std;

bool kuung();
bool isS();
bool isBull();
void ariFront();
void ariTurn(int i);
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

        if (A[i] == 'F') ariFront();
        else ariTurn(i);

        if (kuung()) {
            cout << "Aaaaaah!";
            return 0;
        }

        for (Zombi &z : zombis) z.move();

        if (kuung()) {
            cout << "Aaaaaah!";
            return 0;
        }
    }


    if (!isKuung) cout << "Phew...";

    return 0;
}

bool kuung() {
    for (Zombi &z : zombis) {
        if (z.x == ari.x && z.y == ari.y) {
            if (!isBull() && !isS()) {
                isKuung = true;
                return true;
            }
        }
    }
    return false;
}


bool isS() {
    for (S &s : ss) {
        if (s.x == ari.x && s.y == ari.y) {

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int r = s.x + dx;
                    int c = s.y + dy;
                    if (!inRange(r, c)) continue;

                    bool exists = false;
                    for (Bull &b : bulls) {
                        if (b.x == r && b.y == c) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) bulls.push_back(Bull(r, c));
                }
            }
            return true;
        }
    }
    return false;
}


bool isBull() {
    for (Bull &bull:bulls) {
        if (bull.x == ari.x && bull.y == ari.y) return true; 
    }
    return false;
}

void ariFront() {
    int r = ari.x + dx[ari.direction];
    int c = ari.y + dy[ari.direction];

    if (!inRange(r, c)) return;

    ari.x = r;
    ari.y = c;

    if (kuung()) {
        cout << "Aaaaaah!";
        exit(0);
    }

    isS();
}

void ariTurn(int i) {
    ari.turn(A[i]);

    if (kuung()) {
        cout << "Aaaaaah!";
        return ;
    }
}

inline bool inRange(int r, int c) {
    return 0 <= r  && r < N && 0 <= c && c < N;
}

/*
Aaaaaah!
Phew...
*/