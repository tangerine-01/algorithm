#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PP;

priority_queue <PP, vector<PP>, greater<PP> > mh;
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int temp1; cin >> temp1;
        int temp2; cin >> temp2;

        mh.push({temp2, temp1});
    }

    int end = mh.top().first;
    mh.pop();
    int cnt = 1;

    while(!mh.empty()) {
        // 중요: stack, queue 쓸 때도 많이 사용함
        PP tmp = mh.top();
        mh.pop();
        if (tmp.second < end) continue;
        cnt++;
        end = tmp.first;
    }

    cout << cnt;

    return 0;
}