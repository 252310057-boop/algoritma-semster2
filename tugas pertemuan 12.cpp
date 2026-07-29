#include <iostream>
#include <climits>

using namespace std;

const int V = 5;


int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        cout << j + 1;
        return;
    }

    printPath(parent, parent[j]);
    cout << " -> " << j + 1;
}


void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Jarak terpendek dari " << src + 1 << " ke " << dest + 1 << " adalah: " << dist[dest] << endl;
    cout << "Rute: ";
    printPath(parent, dest);
    cout << endl;
}

int main() {
    
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

  
    dijkstra(graph, 0, 4);

    return 0;
}

