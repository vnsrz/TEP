#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<ii>>;
const ll oo = 1e18;

vector<vector<ll>> floyd_warshall(graph &adj, int N) {
	vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, oo));
	
	for (int u = 1; u <= N; ++u)
		dist[u][u] = 0;
		
	for (int u = 1; u <= N; ++u)
		for (auto [v, w] : adj[u])
			dist[u][v] = w;
			
	for (int k = 1; k <= N; ++k)
		for (int u = 1; u <= N; ++u)
			for (int v = 1; v <= N; ++v)
				if (dist[u][k] < oo and dist[k][v] < oo)
					dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
	
	return dist;
}