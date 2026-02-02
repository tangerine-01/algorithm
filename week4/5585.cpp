#include <iostream>

using namespace std;

int main() {
    int coin[6] = {500, 100, 50, 10, 5, 1};
    int money;
    cin >> money;

    int lift = 1000 - money;
    int count = 0;

    for (int i = 0; i < 6; i++) {
        while (lift >= coin[i]) {
            lift -= coin[i];
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}