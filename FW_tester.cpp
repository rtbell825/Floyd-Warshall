#include "floyd-warshall.cpp"

void fivePointGraphWithNegatives(int verbose) {
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
    int correctOutput[][5] = {
        {0, 1, -3, 2, -4},
        {3, 0, -4, 1, -1},
        {7, 4, 0, 5, 3},
        {2, -1, -5, 0, -2},
        {8, 5, 1, 6, 0}
    };
    bool passed = true;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (fw[i][j] != correctOutput[i][j]) {
                passed = false;
            }
        }
    }
    if (passed == false) {
        if (verbose == 0) {
            cout << "failed: fivePointGraphWithNegatives\n";
        }
        else {
            cout << "output:\n";
            graph.printGraph(fw, 5);
            cout << "failed: fivePointGraphWithNegatives\n";
        }
    }
    else {
        cout << "passed: fivePointGraphWithNegatives\n";
    }
    return;
}

int main() {
    fivePointGraphWithNegatives(1);
    return 0;
}