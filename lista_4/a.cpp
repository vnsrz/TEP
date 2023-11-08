// Bridge
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;
#define LIMIT 50

graph adj(LIMIT);
vector<int> dfs_low(LIMIT);
vector<int> dfs_num(LIMIT);

void dfs_bridge(int u, int p, int& next, vector<ii>& bridges) {
	dfs_low[u] = dfs_num[u] = next++;
	
	for (auto v : adj[u])
		if (not dfs_num[v]) {
			dfs_bridge(v, u, next, bridges);
			
			if (dfs_low[v] > dfs_num[u])
				bridges.emplace_back(u, v);
				
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			
		} else if (v != p)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}

vector<ii> count_bridges(int N) {
	vector<ii> bridges;
	
	for (int u = 1, next = 1; u <= N; ++u)
		if (not dfs_num[u])
			dfs_bridge(u, u, next, bridges);
	
	return bridges;
}

int solve(int n, int m) {
    int u, v;
    for (int i=0; i<m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ii> bridges = count_bridges(n);

    return bridges.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    cout << solve(n,m) << endl;

    return 0;
}