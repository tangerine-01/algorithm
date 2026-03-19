#include <iostream>
#include <stack>

using namespace std;

void calculation(stack<int> &st, char cmd);

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string equation;
    stack<int> numbers;

    cin >> equation;

    for (auto it : equation) {
        if ('0' <= it && it <= '9') numbers.push(it - '0');
        else calculation(numbers, it);
    }

    cout << numbers.top();
}

void calculation(stack<int> &st, char cmd) {
    int b = st.top();
    st.pop();
    int a = st.top();
    st.pop();

    switch (cmd) {
        case '+':
            st.push(a + b);
            break;
        case '-':
            st.push(a - b);
            break;
        case '*':
            st.push(a * b);
            break;
        case '/':
            st.push(a / b);
            break;
    }
}