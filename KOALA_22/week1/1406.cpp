#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> left_s;
stack<char> right_s;

void editor();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string initial_str;
    if (!(cin >> initial_str)) return 0;

    for (char c : initial_str) {
        left_s.push(c);
    }

    int M;
    cin >> M;

    while (M--) {
        editor();
    }

    while (!left_s.empty()) {
        right_s.push(left_s.top());
        left_s.pop();
    }

    while (!right_s.empty()) {
        cout << right_s.top();
        right_s.pop();
    }
    cout << '\n';

    return 0;
}

void editor() {
    char cmd;
    cin >> cmd;

    if (cmd == 'L') {
        if (!left_s.empty()) {
            right_s.push(left_s.top());
            left_s.pop();
        }
    }
    else if (cmd == 'D') {
        if (!right_s.empty()) {
            left_s.push(right_s.top());
            right_s.pop();
        }
    }
    else if (cmd == 'B') {
        if (!left_s.empty()) {
            left_s.pop();
        }
    }
    else if (cmd == 'P') {
        char x;
        cin >> x;
        left_s.push(x);
    }
}