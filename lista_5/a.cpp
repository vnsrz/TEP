// Dijkstra?
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<ii>>;
const int oo { 1000000010 };

vector<int> dijkstra2(const graph &adj, int n) {
    const int oo { 1000000010 };
    vector<int> dist(n,oo);
    vector<int> prev(n);

    int start = 1, distance = 0;
    dist[start] = distance;
    prev[start] = distance;

    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({distance,start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (distance > dist[u]) continue;

        for (auto edge : adj[u]) {
            int w = edge.first;
            int v = edge.second;
            if (dist[u] + w < dist[v]) {
                prev[v] = u;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[n-1] == oo){
        cout << -1 << endl;
        exit(0);
    };
    // cout << "dist " << dist[n-1] << endl;
    return prev;
}

void print_path(const vector<int> &pred, int atual){
    if (atual == 0) return;
    print_path(pred, pred[atual]);
    cout << atual << " ";
}

pair<vector<int>, vector<int>> dijkstra3(const graph &adj, int s, int N) {
    const int oo { 1000000010 };
	vector<int> dist(N + 1, oo), pred(N + 1, oo);
	dist[s] = 0; pred[s] = 0;
    vector<bool> processed(N+1, false);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.emplace(0, s);

	while (not pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (processed[u])
			continue;
		processed[u] = true;
		for (auto [v, w] : adj[u]) {
			if (dist[v] > d + w) {
				dist[v] = d + w;
				pred[v] = u;
				pq.emplace(dist[v], v);
			}
		}
	}
	return { dist, pred };
}

vector<int> dijkstra(graph &adj, int s, int N) {
	vector<int> dist(N + 1, oo), pred(N + 1, oo);
	dist[s] = 0; pred[s] = 0;
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
                pred[v] = u;
				U.emplace(dist[v], v);
			}
		}
	}

    if (dist[N] == oo){
        cout << -1 << endl;
        exit(0);
    }

	return pred;
}

vector<ii> path( const vector<int>& pred, int s, int u) {
	vector<ii> p;
	int v = u;
	do {
		p.push_back(ii(pred[v], v));
		v = pred[v];
	} while (v != s);
	reverse(p.begin(), p.end());
	return p;
}

void solve(graph &adj, int n) {
    vector<int> pred = dijkstra(adj, 1, n);
    vector<ii> p = path(pred, 1, n);
    for (long unsigned int i=0; i<p.size(); i+=2){
        cout << p[i].first << " " << p[i].second << " ";
    }      
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    graph adj(n+1);

    for (int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    solve(adj, n);
    cout << endl;

    return 0;
}