// Pure
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

graph adj(1001);
vector<bool> visited(1001, false);
vector<bool> cycle_stack(1001, false);
set<int> cycle;

bool dfs(int u) {
	if (visited[u])
		return false;
	
	visited[u] = true;
    cycle_stack[u] = true;
    cycle.insert(u);

	for (auto v : adj[u]) 
		if ((not visited[v] and dfs(v)) or cycle_stack[v])
			return true;
	
    cycle_stack[u] = false;
    cycle.erase(u);
	return false;
}

int has_cycle_stack(int N) {
	for (int u = 1; u <= N; ++u)
		if (not visited[u] and dfs(u)){
			return cycle.size();
        }
	return -1;
}

int solve(int n, int m) {
    int u, v;
    for (int i=0; i<m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return has_cycle_stack(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    cout << solve(n,m) << endl;

    return 0;
}