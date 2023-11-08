// Sending email
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<ii>>;
using edge = tuple<int,int,int>;
const int oo { 1000000010 };

vector<int> dijkstra(graph &adj, int s, int N) {
	vector<int> dist(N + 1, oo);
	dist[s] = 0;
	set<ii> U;
	U.emplace(0, s);
	while (not U.empty()) {
		auto [d, u] = *U.begin();
		U.erase(U.begin());
		for (auto [v, w] : adj[u]) {
			if (dist[v] > d + w) {
				if (U.count(ii(dist[v], v)))
					U.erase(ii(dist[v], v));
				dist[v] = d + w;
				U.emplace(dist[v], v);
			}
		}
	}
	return dist;
}

string solve(graph &adj, int n, int start, int target) {
    vector<int> dist = dijkstra(adj, start, n);
    return (dist[target] == oo? "unreachable" : to_string(dist[target]));
    // return dist[target];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tests;
    cin >> tests;

    for (int i=0; i<tests; ++i) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        graph adj(n+1);
        for (int j=0; j<m; ++j) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v,w));       
            adj[v].push_back(make_pair(u,w));       
        }
        cout << "Case #" << i+1 << ": ";
        cout << solve(adj, n, s, t) << endl;
    }

    return 0;
}