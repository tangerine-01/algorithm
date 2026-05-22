#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int node);

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start = 1;
    visited[start] = true;

    int count = 0;
    for (int next : graph[start]) {
        if (!visited[next]) {
            dfs(next);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] && i != start) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}

void dfs(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}