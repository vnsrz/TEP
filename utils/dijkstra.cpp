#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;
using graph = vector<vector<pll>>;
const ll oo = 1e18;

vector<ll> dist;
vector<ll> parent;
graph adj;

void dijkstra(int start) {
    int n = adj.size();
    dist.resize(n, oo);
    parent.resize(n, -1);

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
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        } 
    }
}

vector<ll> get_path(int target) {
    vector<ll> path;

    for (int v=target; v != -1; v=parent[v])
        path.push_back(v);
    
    reverse(path.begin(), path.end());
    return path;
}