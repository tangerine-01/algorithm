#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

string str;
int position;
char picked[10];
bool visited[10] = {0};
int cnt = 0;
bool isFind = false;

void recursive(int depth);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        cnt = 0;
        isFind = false;
        memset(visited, 0, 10);

        cin >> str >> position;

        if (cin.eof()) break;
        
        cout << str << ' ' << position << " = ";
        recursive(0);
        if (!isFind) cout << "No permutation";
        cout << '\n';
    }
    return 0;
}

void recursive(int depth) {
    if (cnt > position) return ;

    if (depth == str.length()) {
        cnt++;
        if (cnt != position) {
            return ;
        }
        for (int i = 0; i < str.length(); i++) {
            cout <<  picked[i];
        }
        isFind = true;

        return ;
    }

    for (int i = 0; i < str.length(); i++) {
        if (visited[i]) continue;

        picked[depth] = str[i];

        visited[i] = true;
        recursive(depth + 1);
        visited[i] = false;
    }
    return ;
}