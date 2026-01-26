#include <iostream>

using namespace std;

struct node {
    node *ptr;
    int data;
};

class Stack {
    private:
        int S_size;
        node *topPtr;
    public:
        Stack() {
            topPtr = NULL;
            S_size = 0;
        }

        void push(int data);
        int pop();
        int size();
        bool empty();
        int top();

        ~Stack() {
            while(!empty()) {
                pop();
            }
        }
};

void Stack::push(int data) {
    node *temp = new node;
    temp -> data = data;
    temp -> ptr = topPtr;

    topPtr = temp;

    S_size++;

    return ;
}

int Stack::pop() {
    if (empty()) return -1;
    int tempData = topPtr -> data;
    node *tempPtr = topPtr;
    topPtr = topPtr -> ptr;
    delete tempPtr;
    S_size--;
    return tempData;
}

int Stack::size() {
    return S_size;
}

bool Stack::empty() {
    return topPtr == NULL;
}

int Stack::top() {
    if (empty()) return -1;
    return topPtr -> data;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, data;
    string cmd;
    Stack s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cmd;
        
        if(cmd == "push") {
            cin >> data;
            s.push(data);
        }
        else if (cmd == "pop") cout << s.pop() << '\n';
        else if (cmd == "size") cout << s.size() << '\n';
        else if (cmd == "empty") cout << (int)s.empty() << '\n';
        else if (cmd == "top") cout << s.top() << '\n';
    }
    return 0;
}