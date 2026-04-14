#include <iostream>
#include <algorithm>

using namespace std;

int number, s;
int psum[100001] = {0};

void slidingWindow();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> number >> s;


    for (int i = 1; i <= number; i++) {
        int temp;
        cin >> temp;

        psum[i] = psum[i - 1] + temp;
    }

    slidingWindow();

    return 0;

}

void slidingWindow() {
    int windowSum = -2147483648;
    
    for (int i = s; i <= number; i++) {
        int currentWS = psum[i] - psum[i - s];

        windowSum = max(windowSum, currentWS);
    }

    cout << windowSum;

    return ;
}