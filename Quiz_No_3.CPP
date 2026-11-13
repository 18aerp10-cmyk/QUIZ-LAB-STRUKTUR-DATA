#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    private:
        int V;
        vector<vector<int>> adjMatrix;
        vector<int> distance;
        vector<int> parent;

        void dfsUntil(int currentVertex, vector<bool>& visited) {
            visited[currentVertex] = true;
            cout << char('A' + currentVertex) << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                    dfsUntil(i, visited);
                }
            }
        }

        void cetakRute(int tujuan) {
            if (parent[tujuan] != -1) {
                cetakRute(parent[tujuan]);
                cout << " -> ";
            }
            cout << char('A' + tujuan);
        }

    public:
        Graph(int jumlahVertex) {
            V = jumlahVertex;
            adjMatrix.resize(V, vector<int>(V, 0));
        }

        void addEdge(int u, int v, int weight) {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight;
        }

        void printAdjMatrix() {
            cout << "  ";
            for (int i = 0; i < V; i++) {
                cout << char('A' + i) << " ";
            }
            cout << endl;

            for (int i = 0; i < V; i++) {
                cout << char('A' + i) << " ";
                for (int j = 0; j < V; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void bfs(int startVertex) {
            vector<bool> visited(V, false);
            queue<int> titikVisit;

            visited[startVertex] = true;
            titikVisit.push(startVertex);

            while (!titikVisit.empty()) {
                int currentVertex = titikVisit.front();
                titikVisit.pop();
                cout << char('A' + currentVertex) << " ";

                for (int i = 0; i < V; i++) {
                    if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                        visited[i] = true;
                        titikVisit.push(i);
                    }
                }
            }
            cout << endl;
        }

        void dfs(int startVertex) {
            vector<bool> visited(V, false);
            dfsUntil(startVertex, visited);
            cout << endl;
        }

        void dijkstra(int source) {
            vector<bool> visited(V, false);
            distance.assign(V, INT_MAX);
            parent.assign(V, -1);
            distance[source] = 0;

            for (int i = 0; i < V; i++) {
                int u = -1;

                for (int j = 0; j < V; j++) {
                    if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                        u = j;
                    }
                }

                if (u == -1 || distance[u] == INT_MAX)
                    break;

                visited[u] = true;

                for (int v = 0; v < V; v++) {
                    if (adjMatrix[u][v] != 0 && !visited[v]) {
                        int newDistance = distance[u] + adjMatrix[u][v];

                        if (newDistance < distance[v]) {
                            distance[v] = newDistance;
                            parent[v] = u;
                        }
                    }
                }
            }
        }

        void tampilRute(int tujuan) {
            if (distance[tujuan] == INT_MAX) {
                cout << "Tidak ada rute menuju vertex tersebut." << endl;
                return;
            }

            cout << "Rute yang dilalui : ";
            cetakRute(tujuan);
            cout << endl;
            cout << "Total jarak       : " << distance[tujuan] << endl;
        }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 4); // A - B
    graph.addEdge(0, 2, 2); // A - C
    graph.addEdge(1, 2, 1); // B - C
    graph.addEdge(1, 3, 5); // B - D
    graph.addEdge(1, 4, 3); // B - E
    graph.addEdge(2, 3, 8); // C - D
    graph.addEdge(2, 4, 6); // C - E
    graph.addEdge(3, 4, 2); // D - E
    graph.addEdge(3, 5, 4); // D - F
    graph.addEdge(4, 5, 3); // E - F

    cout << "Adjacency Matrix :" << endl;
    graph.printAdjMatrix();
    cout << endl;

    char awal, tujuan;

    do {
        cout << "Masukkan vertex awal   : ";
        cin >> awal;

        if (awal < 'A' || awal > 'F') {
            cout << "Vertex awal tidak valid! Masukkan A sampai F.\n\n";
        }

    } while (awal < 'A' || awal > 'F');

    do {
        cout << "Masukkan vertex tujuan : ";
        cin >> tujuan;

        if (tujuan < 'A' || tujuan > 'F') {
            cout << "Vertex tujuan tidak valid! Masukkan A sampai F.\n\n";
        }

    } while (tujuan < 'A' || tujuan > 'F');

    cout << endl;

    cout << "Penelusuran BFS : ";
    graph.bfs(awal - 'A');

    cout << "Penelusuran DFS : ";
    graph.dfs(awal - 'A');
    cout << endl;

    graph.dijkstra(awal - 'A');
    graph.tampilRute(tujuan - 'A');

    return 0;
}
