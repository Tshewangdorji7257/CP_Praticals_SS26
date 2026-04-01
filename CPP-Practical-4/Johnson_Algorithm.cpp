#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

void dijkstra(int src, int V, vector<vector<pair<int,int>>> &adj) {
    vector<int> dist(V, INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto x : adj[u]) {
            int v = x.first;
            int w = x.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest paths from " << src << ": ";
    for(int i = 0; i < V; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (source destination weight):\n";

    for(int i = 0; i < E; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    for(int i = 0; i < V; i++)
        dijkstra(i, V, adj);
}
