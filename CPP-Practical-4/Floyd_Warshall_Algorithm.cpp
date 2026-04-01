#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[V][V];

    cout << "Enter adjacency matrix (use 99999 for INF):\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
