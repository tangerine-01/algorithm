#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

void postorder(int first, int end);

int main() {
    int num;
    while (cin >> num) nums.push_back(num);
    postorder(0, nums.size() -1);

    return 0;
}

void postorder(int first, int end) {
    if (first > end) return;

    int mid = end + 1;
    for(int i = first + 1; i <= end; i++) {
        if (nums[first] < nums[i]) {
            mid = i;
            break;
        }
    }

    postorder(first + 1, mid - 1);
    postorder(mid, end);
    cout << nums[first] << '\n';
}