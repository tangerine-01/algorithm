#include <iostream>
#include <vector>

using namespace std;
// namespace    검색해볼것

int sumTest(int, int);

int main() {
    cout << "안녕";

    vector<int> arr(10, 1);
    // arr(a, b)    a는 칸 수, b는 칸에 다 채울 내용물
    for (auto &it : arr) {  // 향상된 for문
        // auto 자동 자료형 추적(오른쪽 자료형을)
        // &    참조 자료형, pointer 같은 건데 참조까지 자동으로 해줌
        // :    iterator를 가진 객체에서 순서대로 빼와서 넣어줌
            cout << it << endl;
            // endl     개처느린 \n(endline의 의미)
    }
    cout << sumTest(4);
    return 0;
}

int sumTest(int a, int b = 1){
    return a + b;
}