#include <iostream>
#include <string>

using namespace std;

string X, Y;
int diff = 1 << 30;

void getDiff();

int main() {
    cin >> X >> Y;

    getDiff();

    cout << diff;
    return 0;
}

void getDiff() {
    int count = 0;
    for (int i = 0; i < Y.size() - X.size() + 1; i++) {
        int temp = 0;
        for (int j = 0; j < X.size(); j++) {
            if (X[j] != Y[j + i]) temp += 1;
        }
        diff = min(diff, temp);
    }
    return ;
}