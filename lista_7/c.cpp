// Road reparation
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<ii>>;
using edge = tuple<ll, ll, ll>;

typedef struct DSU{
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 1; i < n+1; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) 
            return false;
        if (size[a] < size[b]) 
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
}DSU;

ll kruskal(int N, vector<edge>& es) {
    sort(es.begin(), es.end());

    set<int> visited;
    ll cost = 0;
    DSU dsu(N);

    for (auto [w, u, v] : es)
        if (dsu.unite(u, v)){
            visited.emplace(u);
            visited.emplace(v);
            cost += w;
        }
    if ((int)visited.size() != N) return -1;
    return cost;
}

string solve(vector<edge> &adj, int n) {
    ll cost = kruskal(n, adj);
    if (cost == -1) return "IMPOSSIBLE";
    return to_string(cost);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<edge> adj(m*2);

    for (int i=0; i<m; ++i) {
        ll x, y, w;
        cin >> x >> y >> w;
        adj.push_back(make_tuple(w, x, y));
        adj.push_back(make_tuple(w, y, x));   
    }

    cout << solve(adj, n) << endl;

    return 0;
}