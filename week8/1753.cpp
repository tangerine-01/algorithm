#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> adj[20010];
int dist[20010];

void dijkstra();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E >> K;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    fill(dist, dist + V + 1, INF);

    dijkstra();

    return 0;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

    pq.push({0, K});
    dist[K] = 0;

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < current_distance) continue;

        for (auto& edge : adj[current]) {
            int next = edge.first;
            int weight = edge.second;
            int new_distance = current_distance + weight;

            if (new_distance < dist[next]) {
                dist[next] = new_distance;
                pq.push({new_distance, next});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}