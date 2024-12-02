#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int V, int E, vector<vector<int>>& edges, int start) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print distances
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " Distance: " << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    bellmanFord(V, E, edges, 0);

    return 0;
}
