// Chefland and electricity
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using edge = tuple<ll, ll, ll>;
using graph = vector<edge>;

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

int kruskal(int N, vector<edge> &es) {
    sort(es.begin(), es.end());

    int cost = 0;
    DSU dsu(N);

    for (auto [w, u, v] : es)
        if (dsu.unite(u, v))
            cost += w;

    return cost;
}

void solve(int n) {
    //vector<int> hasElectricity(n+1, 0);
    vector<int> position(n+1);
    string villages;
    graph adj;

    cin >> villages;

    for (int i=1; i<n; ++i) {
        int w = position[i+1] - position[i];
        adj.push_back(make_tuple(w, i, i+1));
    }

    for (int i=1; i<n+1; ++i) {
        cin >> position[i];
        //if(villages[i-1]) hasElectricity[i] = 1;
    }

    cout << kruskal(n, adj) << endl;
    // for (auto [w, u, v] : adj)
    //     cout << u << " " << v << " " << w << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    cin >> t;

    for (int i=0; i<t; ++i) {
        cin >> n;
        solve(n);
    }

    return 0;
}