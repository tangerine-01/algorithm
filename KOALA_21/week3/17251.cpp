#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
vector<int> arr;
int red[1000001] = {0};
int blue[1000001] = {0};

int R = 0;
int B = 0;

char getAnswer();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int numMax = -1;
    for (int i = 0; i < N; i++) {
        numMax = max(numMax, arr[i]);
        red[i] = numMax;
    }

    numMax = -1;
    for (int i = N - 1; i >= 0; i--) {
        numMax = max(numMax, arr[i]);
        blue[i] = numMax;
    }

    cout << getAnswer();

    return 0;
}

char getAnswer() {
    for (int i = 0; i < N - 1; i++) {
        if (red[i] > blue[i + 1]) R++;
        else if (red[i] < blue[i + 1]) B++;
    }

    if (R > B) return 'R';
    else if (R < B) return 'B';
    else return 'X';
}












// 제발 처음 풀이 그대로 밀고가기