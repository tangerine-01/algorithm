#include <iostream>
#include <string>

using namespace std;

struct node {
    node *ptr;
    int data;
};

class Queue {
    private:
        int Q_size;
        node *frontPtr;
        node *backPtr;
    public:
        Queue() {
            frontPtr = backPtr = NULL;
            Q_size = 0;
        }

        void push(int data);
        int pop();
        int size();
        bool empty();
        int front();
        int back();
        ~Queue(){
            while(!empty()){
                pop();
            }
        }
};

void Queue::push(int data) {
    node *temp = new node;
    temp -> data = data;
    temp -> ptr = NULL;

    if (frontPtr == NULL) {
        frontPtr = temp;
        backPtr = temp;
    }
    else {
        backPtr -> ptr = temp;
        backPtr = temp;
    }
    Q_size++;

    return ;
}

int Queue::pop() {
    if (empty()) return -1;
    int tempData = frontPtr -> data;
    node *tempPtr = frontPtr;
    frontPtr = frontPtr -> ptr;
    if (frontPtr == NULL) backPtr = NULL;
    delete tempPtr;
    Q_size--;
    return tempData;
}

int Queue::size() {
    return Q_size;
}

bool Queue::empty() {
    return frontPtr == NULL;
}

int Queue::front() {
    if (empty()) return -1;
    return frontPtr -> data;
}

int Queue::back() {
    if (empty()) return -1;
    return backPtr -> data;
}

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, data;
    string cmd;
    Queue q;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> data;
            q.push(data);
        }
        else if (cmd == "pop") cout << q.pop() << '\n';
        else if (cmd == "size") cout << q.size() << '\n';
        else if (cmd == "empty") cout << (int)q.empty() << '\n';
        else if (cmd == "front") cout << q.front() << '\n';
        else if (cmd == "back") cout << q.back() << '\n';
    }
    return 0;
}