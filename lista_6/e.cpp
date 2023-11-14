// Transit tree path
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<ii>>;

int solve(graph &adj, vector<ii> &query, int k) {

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
        query.push_back(make_pair(u,v));   
    }

    solve(adj, query, k);

    return 0;
}