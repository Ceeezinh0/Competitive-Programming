#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Aresta {
    int destino, custo;
};

void dijkstra(int n, vector<vector<Aresta>>& adj, int origem, vector<int>& dist) {
    dist.assign(n + 1, INF);
    dist[origem] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, origem});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& aresta : adj[u]) {
            int v = aresta.destino;
            int custo = aresta.custo;

            if (dist[u] + custo < dist[v]) {
                dist[v] = dist[u] + custo;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<vector<Aresta>> adj(n + 1);

        for (int i = 0; i < m; ++i) {
            int u, v, custo;
            cin >> u >> v >> custo;
            
            adj[u].push_back({v, custo});

            bool encontrado = false;
            for (auto& aresta : adj[v]) {
                if (aresta.destino == u) {
                    encontrado = true;
                    if (aresta.custo > custo) {
                        aresta.custo = 0;
                    } else if (custo >= aresta.custo) {
                        adj[u].back().custo = 0;
                    }
                }
            }

            if (!encontrado) {
                adj[v].push_back({u, 0});
            }
        }

        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int origem, destino;
            cin >> origem >> destino;

            vector<int> dist;
            dijkstra(n, adj, origem, dist);

            if (dist[destino] == INF) {
                cout << "Nao e possivel entregar a carta" << endl;
            } else {
                cout << dist[destino] << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
