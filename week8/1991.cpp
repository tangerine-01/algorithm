#include <iostream>
#include <string.h>

using namespace std;

const int MAX_NODE = 27;
int binary_tree[MAX_NODE][2];

void preorder(int root);
void inorder(int root);
void postorder(int root);

int main() {
    int N;
    cin >> N;

    memset(binary_tree, -1, sizeof(binary_tree));

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;

        int r = root - 'A';

        if (left != '.') binary_tree[r][0] = left - 'A';
        if (right != '.') binary_tree[r][1] = right - 'A';
    }

    preorder(0);
    cout << '\n';

    inorder(0);
    cout << '\n';

    postorder(0);
    cout << '\n';

    return 0;
}

void preorder(int root) {
    if (root == -1) return ;

    cout << char(root + 'A');
    preorder(binary_tree[root][0]);
    preorder(binary_tree[root][1]);
}

void inorder(int root) {
    if (root == -1) return ;
    
    inorder(binary_tree[root][0]);
    cout << char(root + 'A');
    inorder(binary_tree[root][1]);
}

void postorder(int root) {
    if (root == -1) return ;

    postorder(binary_tree[root][0]);
    postorder(binary_tree[root][1]);
    cout << char(root + 'A');
}