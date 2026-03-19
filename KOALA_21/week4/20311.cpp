#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> colors; // (개수, 색깔번호)
    
    for (int i = 1; i <= K; i++) {
        int c;
        cin >> c;
        colors.push_back({c, i});
    }
    
    // 개수가 많은 순서대로 정렬
    sort(colors.begin(), colors.end(), greater<pair<int, int>>());
    
    // 불가능 조건 체크
    int max_count = colors[0].first;
    if (max_count > (N + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }
    
    vector<int> result(N);
    int idx = 0;
    
    // 각 색깔을 배치
    for (auto& p : colors) {
        int count = p.first;
        int color = p.second;
        
        for (int i = 0; i < count; i++) {
            result[idx] = color;
            idx += 2;
            // 짝수 인덱스를 다 채웠으면 홀수 인덱스로
            if (idx >= N) {
                idx = 1;
            }
        }
    }
    
    // 출력
    for (int i = 0; i < N; i++) {
        cout << result[i];
        if (i < N - 1) cout << ' ';
    }
    cout << '\n';
    
    return 0;
}