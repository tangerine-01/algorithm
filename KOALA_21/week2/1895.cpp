#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> VI;

int filter(int r, int c, vector<VI> &arr);

int main() {
    int R, C, T;
    int count = 0;

    cin >> R >> C;

    vector<VI> arr(R, VI(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> T;

    for (int i = 0; i < R - 2; i++) {
        for (int j = 0; j < C - 2; j++) {
            if (filter(i, j, arr) >= T) count++;
        }
    }

    cout << count;

    return 0;
}

int filter(int r, int c, vector<VI> &arr) {
    vector<int> temp;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp.push_back(arr[r + i][c + j]);
        }
    }

    sort(temp.begin(), temp.end());

    return temp[4];
}






/*
  vector<int> arr;
  for(~){
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }                                                                                            
*/