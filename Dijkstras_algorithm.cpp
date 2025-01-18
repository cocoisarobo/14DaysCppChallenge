#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

// const INF = INT_MAX;

vector<int> sol(int n, vector<vector<pair<int, int>>>& graph, int start) {
    // Initialize distances with infinity
    vector<int> dist(n, numeric_limits<int>::max()); //(n, INF)
    dist[start] = 0;

    // Min-heap priority queue to select the edge with the smallest weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the distance is greater than the recorded distance, skip processing
        if (current_dist > dist[u]) continue;

        // Explore neighbors
        // for(auto [v,w] : graph[u]) {}
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Replace infinity with -1 for unreachable nodes
    // for(int& d : dist) { if(d==INF) d = -1; }
    for (int i = 0; i < n; i++) {
        if (dist[i] == numeric_limits<int>::max()) {
            dist[i] = -1;
        }
    }

    return dist;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int start;
    cin >> start;
// please don't modify the main function
    vector<int> result = sol(n, graph, start);

    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }
    
    return 0;
}
