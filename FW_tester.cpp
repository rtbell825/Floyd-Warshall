#include "floyd-warshall.cpp"

int main() {
    Graph graph;
    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 2, 8);
    graph.addEdge(0, 4, -4);
    graph.addEdge(1, 3, 1);
    graph.addEdge(1, 4, 7);
    graph.addEdge(2, 1, 4);
    graph.addEdge(3, 0, 2);
    graph.addEdge(3, 2, -5);
    graph.addEdge(4, 3, 6);
    int** fw = graph.floydWarshall();
    graph.printGraph(fw, 5);
    return 0;
}