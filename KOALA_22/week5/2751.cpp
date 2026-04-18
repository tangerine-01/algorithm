#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num,temp;
    vector<int> arr;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());
    
    for(int i = 0; i < num; i++) cout << arr[i] << '\n';
}