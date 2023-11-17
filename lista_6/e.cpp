// Transit tree path
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;
using ii = pair <int, int>;
using graph = vector<vector<ii>>;
const ll oo = 1e18;

vector<ll> dijkstra(graph &adj, int start) {
    int n = adj.size();
    vector<ll> dist(n, oo);

    dist[start] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll distance = pq.top().first;
        pq.pop();

        if (distance != dist[u]) continue;

        for (auto neighbor : adj[u]) {
            ll v = neighbor.first;
            ll w = neighbor.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        } 
    }

    return dist;
}

void solve(graph &adj, vector<ii> &query, int k) {
    vector<ll> k_dist = dijkstra(adj, k);
    for (auto item : query) {
        int x = item.first;
        int y = item.second;
        ll total_dist = k_dist[y] + k_dist[x];
        cout << total_dist << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, k;
    cin >> n;
    graph adj(n+1);
    
    for (int i=1; i<n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    cin >> q >> k;
    vector<ii> query(q);

    for (int i=0; i<q; ++i) {
        int u, v;
        cin >> u >> v;
        query[i] = make_pair(u,v);   
    }

    solve(adj, query, k);

    return 0;
}