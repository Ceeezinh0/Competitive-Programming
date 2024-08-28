#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Aresta {
    int destino, custo;
};

// Função para encontrar o menor caminho usando o algoritmo de Dijkstra
vector<int> dijkstra(int n, vector<vector<Aresta>>& adj, int origem) {
    vector<int> dist(n + 1, INF);
    dist[origem] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, origem});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto& aresta : adj[u]) {
            int v = aresta.destino;
            int custo = aresta.custo;

            if (dist[u] + custo < dist[v]) {
                dist[v] = dist[u] + custo;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int N, M, S, P;

    while (cin >> N >> M >> S >> P) {
        vector<vector<Aresta>> adj(N + 1);

        for (int i = 0; i < M; ++i) {
            int u, v, custo;
            cin >> u >> v >> custo;
            adj[u].push_back({v, custo});
            adj[v].push_back({u, custo});
        }

        vector<int> destinos(P);
        for (int i = 0; i < P; ++i) {
            cin >> destinos[i];
        }

        vector<int> dist = dijkstra(N, adj, S);

        int menorCusto = INF;
        for (int destino : destinos) {
            if (dist[destino] < menorCusto) {
                menorCusto = dist[destino];
            }
        }

        cout << menorCusto << endl;
    }

    return 0;
}
