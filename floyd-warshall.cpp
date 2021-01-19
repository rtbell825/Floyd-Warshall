#include <iostream>
#include <string>
using namespace std;

const int INF = 100001;
const int NEGINF = -100001;
const int MAXSIZE = 100;
/* 
 * This class creates a weighted and directed graph implimented using an adjacency matrix with a max size of 100
 * Weights must be between +5000 and -5000
*/
class Graph {
    public:
        /*
         * Constructor initalizes V and the internal matrix.
         * Internal matrix is initally filled with negative infinities. 
        */
        Graph() {
            V = 0;
            for (int i = 0; i < MAXSIZE; i++) {
                for (int j = 0; j < MAXSIZE; j++) {
                    matrix[i][j] = NEGINF;
                }
            }
        }

        /*
         * Add edge only if it's between 5000 and -5000 to the internal matrix. If the edge is accepted we flip all the 
         * negative infinities in that row to positive ones except for the assigned position which we fill with the weight
         * and the diagonal which we fill with a zero. 
        */
        void addEdge(int v1, int v2, int w) {
            try
            {
                if ((w > 5000) || (w < -5000)) {
                    throw(w);
                }
            }
            catch(int weight)
            {
                std::cerr << "Weight " << weight << " is out of bounds.\n";
            }
            
            if (matrix[v1][0] == NEGINF) {
                V = V + 1;
                for (int i = 0; i < MAXSIZE; i++) {
                    if (v1 == i) {
                        matrix[v1][i] = 0;
                    }
                    else {
                        matrix[v1][i] = INF;
                    }
                }
            }
            if (matrix[v2][0] == NEGINF) {
                V = V + 1;
                for (int i = 0; i < MAXSIZE; i++) {
                    if (v2 == i) {
                        matrix[v2][i] = 0;
                    }
                    else {
                        matrix[v2][i] = INF;
                    }
                }
            }
            matrix[v1][v2] = w;
        }

        /*
         * Floyd-Warshall algorithm runs in V^3 time. Finds the shortest all pairs of the internal matrix and returns 
         * the length of the shortest paths between these pairs for every pair in a VxV matrix. 
        */
        int** floydWarshall() {
            int** dist;
            dist = new int *[V];
            for (int i = 0; i < V; i++) {
                dist[i] = new int[V];
                for (int j = 0; j < V; j++) {
                    dist[i][j] = matrix[i][j];
                }
            }
            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            return dist;
        }

        /*
         * Polymorphic method that prints the internal matrix if given no arguments. 
        */
        void printGraph() {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    string output = "";
                    if (matrix[i][j] == NEGINF) {
                        output = "-INF ";
                    }
                    else if (matrix[i][j] == INF) {
                        output = "INF  ";
                    }
                    else {
                        output = to_string(matrix[i][j]) + "    ";
                    }
                    cout << output;
                }
                cout << "\n";
            }
            cout << "\n";
        }

        /*
         * Polymorphic method that prints a provided 2D graph.
        */
        void printGraph(int** graph, int size) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    string output = "";
                    if (graph[i][j] == NEGINF) {
                        output = "-INF ";
                    }
                    else if (graph[i][j] == INF) {
                        output = "INF  ";
                    }
                    else {
                        output = to_string(graph[i][j]) + "    ";
                    }
                    cout << output;
                }
                cout << "\n";
            }
            cout << "\n";
        }
    private:
        int V; // Number of verticies kept track of when assigning edges. 
        int matrix[MAXSIZE][MAXSIZE]; // Internal adjacency matrix
};