//#include "Algorithms.h"
//#include <queue>
//#include <functional>
//#include <climits>
//#include <algorithm>
//#include <numeric>
//
//// Implementacja algorytmu Prima dla reprezentacji macierzowej
//void Algorithms::primMST(GraphMatrix& graph) {
//    int vertices = graph.getDirVertices();
//    std::vector<int> key(vertices, INT_MAX);
//    std::vector<bool> inMST(vertices, false);
//    std::vector<int> parent(vertices, -1);
//    key[0] = 0;
//
//    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
//    pq.emplace(0, 0);
//
//    while (!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//
//        inMST[u] = true;
//
//        for (int v = 0; v < vertices; ++v) {
//            int weight = graph.getEdgeWeight(u, v);
//            if (weight && !inMST[v] && key[v] > weight) {
//                key[v] = weight;
//                pq.emplace(key[v], v);
//                parent[v] = u;
//            }
//        }
//    }
//
//    // Wyświetlanie wyników
//    for (int i = 1; i < vertices; ++i) {
//        std::cout << parent[i] << " - " << i << " \t" << graph.getEdgeWeight(i, parent[i]) << std::endl;
//    }
//}
//
//// Implementacja algorytmu Kruskala dla reprezentacji macierzowej
//void Algorithms::kruskalMST(GraphMatrix& graph) {
//    int vertices = graph.getDirVertices();
//    std::vector<std::tuple<int, int, int>> edges;
//
//    for (int u = 0; u < vertices; ++u) {
//        for (int v = u + 1; v < vertices; ++v) {
//            if (int weight = graph.getEdgeWeight(u, v)) {
//                edges.emplace_back(weight, u, v);
//            }
//        }
//    }
//
//    std::sort(edges.begin(), edges.end());
//
//    std::vector<int> parent(vertices);
//    std::iota(parent.begin(), parent.end(), 0);
//
//    std::function<int(int)> find = [&](int u) {
//        return parent[u] == u ? u : parent[u] = find(parent[u]);
//    };
//
//    auto unite = [&](int u, int v) {
//        parent[find(u)] = find(v);
//    };
//
//    for (const auto& [weight, u, v] : edges) {
//        if (find(u) != find(v)) {
//            std::cout << u << " - " << v << " \t" << weight << std::endl;
//            unite(u, v);
//        }
//    }
//}
//
//// Implementacja algorytmu Dijkstry dla reprezentacji macierzowej
//void Algorithms::dijkstraShortestPath(GraphMatrix& graph, int startVertex) {
//    int vertices = graph.getDirVertices();
//    std::vector<int> distance(vertices, INT_MAX);
//    distance[startVertex] = 0;
//
//    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
//    pq.emplace(0, startVertex);
//
//    while (!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//
//        for (int v = 0; v < vertices; ++v) {
//            int weight = graph.getEdgeWeight(u, v);
//            if (weight && distance[v] > distance[u] + weight) {
//                distance[v] = distance[u] + weight;
//                pq.emplace(distance[v], v);
//            }
//        }
//    }
//
//    // Wyświetlanie wyników
//    for (int i = 0; i < vertices; ++i) {
//        std::cout << "Odległość od " << startVertex << " do " << i << " wynosi " << distance[i] << std::endl;
//    }
//}
//
//// Implementacja algorytmu Bellmana-Forda dla reprezentacji macierzowej
//void Algorithms::bellmanFordShortestPath(GraphMatrix& graph, int startVertex) {
//    int vertices = graph.getDirVertices();
//    std::vector<int> distance(vertices, INT_MAX);
//    distance[startVertex] = 0;
//
//    std::vector<std::tuple<int, int, int>> edges;
//    for (int u = 0; u < vertices; ++u) {
//        for (int v = 0; v < vertices; ++v) {
//            if (int weight = graph.getEdgeWeight(u, v)) {
//                edges.emplace_back(u, v, weight);
//            }
//        }
//    }
//
//    for (int i = 0; i < vertices - 1; ++i) {
//        for (const auto& [u, v, weight] : edges) {
//            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
//                distance[v] = distance[u] + weight;
//            }
//        }
//    }
//
//    // Sprawdzanie cykli ujemnych
//    for (const auto& [u, v, weight] : edges) {
//        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
//            std::cerr << "Graf zawiera cykl o ujemnej wadze!" << std::endl;
//            return;
//        }
//    }
//
//    // Wyświetlanie wyników
//    for (int i = 0; i < vertices; ++i) {
//        std::cout << "Odległość od " << startVertex << " do " << i << " wynosi " << distance[i] << std::endl;
//    }
//}
//
//// Implementacja algorytmów dla reprezentacji listowej analogicznie do powyższych
//void Algorithms::primMST(GraphList& graph) {
//    // Implementacja algorytmu Prima dla grafu listowego
//}
//
//void Algorithms::kruskalMST(GraphList& graph) {
//    // Implementacja algorytmu Kruskala dla grafu listowego
//}
//
//void Algorithms::dijkstraShortestPath(GraphList& graph, int startVertex) {
//    // Implementacja algorytmu Dijkstry dla grafu listowego
//}
//
//void Algorithms::bellmanFordShortestPath(GraphList& graph, int startVertex) {
//    // Implementacja algorytmu Bellmana-Forda dla grafu listowego
//}
