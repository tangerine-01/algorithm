#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search();
bool isTrue(char a, int i);

vector<string> students;
int student_len = 0;
int digits = 0;
int N;


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        students.push_back(temp);
    }

    student_len = students[0].size() - 1;

    cout << search();

    return 0;
}

int search() {
    for (int i = student_len; i >= 0; i--) {
        char temp = students[0][student_len - i];
        if (isTrue(temp, i)) digits++;
        else return digits;
    }

    return student_len;
}

bool isTrue(char a, int i) {
    for (int j = 1; j < N; j++) {
        if (a != students[j][i]) return false;
    }
    return true;
}