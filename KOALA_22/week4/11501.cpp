#include <iostream>
#include <vector>

using namespace std;

int T, N;

void gameStart();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        gameStart();
    }

    return 0;
}

void gameStart() {
    long long profit = 0;
    vector<int> day;

    for (int i = 0; i < N; i++) {
        int temp; cin >> temp;
        day.push_back(temp);
    }

    int maxPrice = 0;

    for (int i = (int)day.size() - 1; i >= 0; i--) {
        if (day[i] > maxPrice)
            maxPrice = day[i];
        else
            profit += maxPrice - day[i];
    }

    cout << profit << "\n";

    return ;
}