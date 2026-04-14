#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X;
vector<int> arrA;
vector<int> arrB;
bool check[200002] = {false};
int useM = 0;
int point = 0;

void getMaxpoint(int a, int b, int num);
void getAnswer();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int tempA, tempB;
        cin >> tempA >> tempB;

        arrA.push_back(tempA);
        arrB.push_back(tempB);

        getMaxpoint(tempA, tempB, i);
    }

    getAnswer();

    return 0;
}

void getMaxpoint(int a, int b, int num) {
    if (a > b) {
        point += a;
        useM += 5000;
        check[2 * num + 1] = true;
    }
    else if (a < b) {
        point += b;
        useM += 1000;
        check[2 * num + 2] = true;
    }
    else {
        point += b;
        useM += 1000;
        check[2 * num + 2] = true;
    }

    return ;
}

void getAnswer() {
    vector<int> candidates;
    for (int i = 0; i < N; i++) {
        if (check[2 * i + 1]) candidates.push_back(i);
    }
    sort(candidates.begin(), candidates.end(), [](int x, int y) {
        return (arrA[x] - arrB[x]) < (arrA[y] - arrB[y]);
    });

    for (int idx : candidates) {
        if (useM <= X) break;
        point = point - arrA[idx] + arrB[idx];
        useM -= 4000;
    }

    cout << point;
}