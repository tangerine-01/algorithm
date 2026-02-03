#include <iostream>

using namespace std;

// typedef pair<int,int> xy;

pair <int, int> king_position, dol_position;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inRange(int r, int c);
int cmdToDirection (string &cmd);
pair <int, int> getPosition (string position);
string getLastPosition(pair <int, int> &mal);
void game();
bool isDol(int d);
bool isDolOut(int d);
bool isKingOut(int d);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string temp_position;
    int N, temp;

    cin >> temp_position;
    king_position = getPosition(temp_position);

    cin >> temp_position;
    dol_position = getPosition(temp_position);
   
    cin >> N;

    for (int i = 0; i < N; i++) {
        game();
    }

    cout << getLastPosition(king_position) << '\n' << getLastPosition(dol_position);

    return 0;
}

// inline 그냥 코드 바로 붙이는거임. 함수 칸 새로 안 열게 됨. 그냥 원래 함수 칸 안에 넣어버림.

inline bool inRange(int r, int c) {
    return 0 <= r  && r < 8 && 0 <= c && c < 8;
}

int cmdToDirection (string &cmd) {
    if (cmd == "R") return 0;
    if (cmd == "RB") return 1;
    if (cmd == "B") return 2;
    if (cmd == "LB") return 3;
    if (cmd == "L") return 4;
    if (cmd == "LT") return 5;
    if (cmd == "T") return 6;
    if (cmd == "RT") return 7;

    return -1;
}

pair <int, int> getPosition (string position) {
    pair <int, int> temp;

    temp.first = 7 - (position[1] - '1');
    temp.second = position[0] - 'A';
    
    return temp; 
}

string getLastPosition(pair <int, int> &mal) {
    string temp;

    temp += mal.second + 'A';
    temp += (7 - mal.first) + '1';

    return temp;
}

void game() {
    string cmd;
    cin >> cmd;

    int direction = cmdToDirection(cmd);
    
    if (isDol(direction)) {
        if (isDolOut(direction)) return ;

        dol_position.first += dy[direction];
        dol_position.second += dx[direction];

        king_position.first += dy[direction];
        king_position.second += dx[direction];

        return ;
    }

    if (isKingOut(direction)) return ;

    king_position.first += dy[direction];
    king_position.second += dx[direction];

    return ;
}

bool isDol(int d) {
    return king_position.first + dy[d] == dol_position.first 
            && king_position.second + dx[d] == dol_position.second;
}

bool isDolOut(int d) {
    return !inRange(dol_position.first + dy[d] 
                    , dol_position.second + dx[d]);
}

bool isKingOut(int d) {
    return !inRange(king_position.first + dy[d] 
                    , king_position.second + dx[d]);
}