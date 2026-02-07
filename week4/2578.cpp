#include <iostream>

using namespace std;

int withdraw[5][5];
int society_ruler = 0;
bool bingo = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> withdraw[i][j];
        }
    }

    while (!bingo) {
        miniGame()
    }

    return 0;
}

void miniGame() {
    cin >> society_ruler;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (society_ruler == withdraw[i][j]) withdraw[i][j] = -1;
        }
    }
}

void checkBingo() {
    for (int i = 0; i < 5; i++) {

    }
}

// 개노가다로 하나하나 확인하고 카운트 재서 while 빙고문 종료 후 출력하게 하기