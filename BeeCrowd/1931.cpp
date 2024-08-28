#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Aresta {
    int destino;
    long long custo;
};

void dijkstra(int n, vector<vector<Aresta>>& adj, vector<vector<long long>>& dist) {
    dist[1][0] = 0;
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second.first;
        int paridade = pq.top().second.second;
        pq.pop();

        if (d > dist[u][paridade]) continue;

        for (auto& aresta : adj[u]) {
            int v = aresta.destino;
            long long custo = aresta.custo;
            int nova_paridade = 1 - paridade;

            if (dist[u][paridade] + custo < dist[v][nova_paridade]) {
                dist[v][nova_paridade] = dist[u][paridade] + custo;
                pq.push({dist[v][nova_paridade], {v, nova_paridade}});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Aresta>> adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long custo;
        cin >> u >> v >> custo;
        adj[u].push_back({v, custo});
        adj[v].push_back({u, custo});
    }

    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    dijkstra(n, adj, dist);

    if (dist[n][0] == INF) {
        cout << "-1" << endl;
    } else {
        cout << dist[n][0] << endl;
    }

    return 0;
}
