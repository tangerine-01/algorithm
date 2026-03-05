#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 1001;

vector<int> graph[MAX];
bool visited[MAX];

void bfs(int start);
void dfs(int node);

int main() {
    int N, M, V;

    cin >> N >> M >> V;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto &g : graph) {
        sort(g.begin(), g.end());
    }

    memset(visited, 0, sizeof(visited));
    dfs(V);

    cout << '\n';

    memset(visited, 0, sizeof(visited));
    bfs(V);
    
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto next : graph[node]) {
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
        }
    }
}

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (auto next : graph[node]) {
        if (visited[next]) continue;
        dfs(next);
    }
}