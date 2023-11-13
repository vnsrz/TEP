#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;
const int MAX { 1000 };

graph adj(MAX);
bitset<MAX> visited;

void dfs(int u) {
	if (visited[u]) return;

	// visita/processa u

	visited[u] = true;
	for (auto v : adj[u])
		dfs(v);
}