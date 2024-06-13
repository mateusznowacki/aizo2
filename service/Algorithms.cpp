#include "Algorithms.h"
#include <climits>
#include <iostream>
#include <queue>
#include <algorithm>

// Prim's algorithm using adjacency matrix
void Algorithms::primMSTMatrix(Graph graph) {
    int vertices = graph.getVertices();
    int **adjMatrix = graph.getAdjMatrix();
    int *parent = new int[vertices];
    int *key = new int[vertices];
    bool *mstSet = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

  //  printMST(parent, vertices, adjMatrix);
    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

// Prim's algorithm using adjacency list
void Algorithms::primMSTList(Graph graph) {
    int vertices = graph.getVertices();
    Graph::Node **adjList = graph.getAdjList();
    int *parent = new int[vertices];
    int *key = new int[vertices];
    bool *mstSet = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        for (Graph::Node *node = adjList[u]; node != nullptr; node = node->next) {
            int v = node->vertex;
            if (!mstSet[v] && node->weight < key[v]) {
                parent[v] = u;
                key[v] = node->weight;
            }
        }
    }

 //   printMST(parent, vertices, graph.getAdjMatrix());
    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

// Helper function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int Algorithms::minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void Algorithms::printMST(int parent[], int n, int **graph) {
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Kruskal's algorithm using adjacency matrix
void Algorithms::kruskalMSTMatrix(Graph graph) {
    int vertices = graph.getVertices();
    int **adjMatrix = graph.getAdjMatrix();
    int edgesCount = 0;

    // Count the number of edges
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (adjMatrix[i][j]) {
                edgesCount++;
            }
        }
    }

    Edge *edges = new Edge[edgesCount];
    int index = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (adjMatrix[i][j]) {
                edges[index++] = {i, j, adjMatrix[i][j]};
            }
        }
    }

    // Sort edges by weight
    std::sort(edges, edges + edgesCount, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int *parent = new int[vertices];
    int *rank = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge *result = new Edge[vertices - 1];
    int e = 0;
    for (int i = 0; i < edgesCount && e < vertices - 1; i++) {
        Edge edge = edges[i];
        int u = find(parent, edge.src);
        int v = find(parent, edge.dest);

        if (u != v) {
            result[e++] = edge;
            Union(parent, rank, u, v);
        }
    }

    //std::cout << "Edges in MST\n";
    for (int i = 0; i < e; i++) {
        std::cout << result[i].src << " - " << result[i].dest << " \t" << result[i].weight << " \n";
    }

    delete[] edges;
    delete[] parent;
    delete[] rank;
    delete[] result;
}

// Kruskal's algorithm using adjacency list
void Algorithms::kruskalMSTList(Graph graph) {
    int vertices = graph.getVertices();
    Graph::Node **adjList = graph.getAdjList();
    int edgesCount = 0;

    // Count the number of edges
    for (int i = 0; i < vertices; i++) {
        for (Graph::Node *node = adjList[i]; node != nullptr; node = node->next) {
            if (i < node->vertex) {
                edgesCount++;
            }
        }
    }

    Edge *edges = new Edge[edgesCount];
    int index = 0;
    for (int i = 0; i < vertices; i++) {
        for (Graph::Node *node = adjList[i]; node != nullptr; node = node->next) {
            if (i < node->vertex) {
                edges[index++] = {i, node->vertex, node->weight};
            }
        }
    }

    // Sort edges by weight
    std::sort(edges, edges + edgesCount, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int *parent = new int[vertices];
    int *rank = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge *result = new Edge[vertices - 1];
    int e = 0;
    for (int i = 0; i < edgesCount && e < vertices - 1; i++) {
        Edge edge = edges[i];
        int u = find(parent, edge.src);
        int v = find(parent, edge.dest);

        if (u != v) {
            result[e++] = edge;
            Union(parent, rank, u, v);
        }
    }

    //std::cout << "Edges in MST\n";
    for (int i = 0; i < e; i++) {
        std::cout << result[i].src << " - " << result[i].dest << " \t" << result[i].weight << " \n";
    }

    delete[] edges;
    delete[] parent;
    delete[] rank;
    delete[] result;
}

// Helper functions for Kruskal's algorithm
int Algorithms::find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void Algorithms::Union(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
void Algorithms::dijkstraMatrix(Graph graph, int src, int dest) {
    int vertices = graph.getVertices();
    int **adjMatrix = graph.getAdjMatrix();
    int *dist = new int[vertices];
    bool *sptSet = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(dist, sptSet, vertices);
        sptSet[u] = true;

        if (u == dest) break;

        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v])
                dist[v] = dist[u] + adjMatrix[u][v];
        }
    }

 //   std::cout << "Vertex \t Distance from Source\n";
   // for (int i = 0; i < vertices; i++)
     //   std::cout << i << " \t " << dist[i] << " \n";

    delete[] dist;
    delete[] sptSet;
}
void Algorithms::dijkstraList(Graph graph, int src, int dest) {
    int vertices = graph.getVertices();
    Graph::Node **adjList = graph.getAdjList();
    int *dist = new int[vertices];
    bool *sptSet = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(dist, sptSet, vertices);
        sptSet[u] = true;

        if (u == dest) break;

        for (Graph::Node *node = adjList[u]; node != nullptr; node = node->next) {
            int v = node->vertex;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + node->weight < dist[v])
                dist[v] = dist[u] + node->weight;
        }
    }

 //   std::cout << "Vertex \t Distance from Source\n";
  //  for (int i = 0; i < vertices; i++)
      //  std::cout << i << " \t " << dist[i] << " \n";

    delete[] dist;
    delete[] sptSet;
}

void Algorithms::bellmanFordMatrix(Graph graph, int src, int dest) {
    int vertices = graph.getVertices();
    int **adjMatrix = graph.getAdjMatrix();
    int *dist = new int[vertices];

    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= vertices - 1; i++) {
        for (int u = 0; u < vertices; u++) {
            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v])
                    dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
        if (dist[dest] != INT_MAX) break;
    }

    for (int u = 0; u < vertices; u++) {
        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                //std::cout << "Graph contains negative weight cycle\n";
                delete[] dist;
                return;
            }
        }
    }

    //std::cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < vertices; i++)
        //std::cout << i << " \t " << dist[i] << " \n";

    delete[] dist;
}

void Algorithms::bellmanFordList(Graph graph, int src, int dest) {
    int vertices = graph.getVertices();
    Graph::Node **adjList = graph.getAdjList();
    int *dist = new int[vertices];

    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= vertices - 1; i++) {
        for (int u = 0; u < vertices; u++) {
            for (Graph::Node *node = adjList[u]; node != nullptr; node = node->next) {
                int v = node->vertex;
                int weight = node->weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }
        if (dist[dest] != INT_MAX) break;
    }

    for (int u = 0; u < vertices; u++) {
        for (Graph::Node *node = adjList[u]; node != nullptr; node = node->next) {
            int v = node->vertex;
            int weight = node->weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                //std::cout << "Graph contains negative weight cycle\n";
                delete[] dist;
                return;
            }
        }
    }

    //std::cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < vertices; i++)
        //std::cout << i << " \t " << dist[i] << " \n";

    delete[] dist;
}

// Ford-Fulkerson algorithm using adjacency matrix
void Algorithms::fordFulkersonMatrix(Graph graph, int source, int sink) {
    int vertices = graph.getVertices();
    int **adjMatrix = graph.getAdjMatrix();
    int **rGraph = new int *[vertices];
    for (int i = 0; i < vertices; i++) {
        rGraph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
            rGraph[i][j] = adjMatrix[i][j];
    }

    int *parent = new int[vertices];
    int maxFlow = 0;

    while (bfs(rGraph, source, sink, parent, vertices)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, rGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    //std::cout << "The maximum possible flow is " << maxFlow << "\n";

    for (int i = 0; i < vertices; i++)
        delete[] rGraph[i];
    delete[] rGraph;
    delete[] parent;
}

// Ford-Fulkerson algorithm using adjacency list
void Algorithms::fordFulkersonList(Graph graph, int source, int sink) {
    int vertices = graph.getVertices();
    int **rGraph = new int *[vertices];
    for (int i = 0; i < vertices; i++) {
        rGraph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
            rGraph[i][j] = 0;
    }

    Graph::Node **adjList = graph.getAdjList();
    for (int u = 0; u < vertices; u++) {
        for (Graph::Node *node = adjList[u]; node != nullptr; node = node->next) {
            int v = node->vertex;
            rGraph[u][v] = node->weight;
        }
    }

    int *parent = new int[vertices];
    int maxFlow = 0;

    while (bfs(rGraph, source, sink, parent, vertices)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, rGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    //std::cout << "The maximum possible flow is " << maxFlow << "\n";

    for (int i = 0; i < vertices; i++)
        delete[] rGraph[i];
    delete[] rGraph;
    delete[] parent;
}

// Helper function for Ford-Fulkerson algorithm
bool Algorithms::bfs(int **rGraph, int s, int t, int parent[], int vertices) {
    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    delete[] visited;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    delete[] visited;
    return false;
}
