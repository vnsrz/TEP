// Bicoloring
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;

const int NONE = 0, BLUE = 1, RED = 2;

bool bfs(int s, vector<vector<int>> &adj, vector<int> &color){
	queue<int> q; q.push(s);
	color[s] = BLUE;
	
	while (not q.empty()) {
		auto u = q.front(); q.pop();
		for (auto v : adj[u]) {
			if (color[v] == NONE) {
				color[v] = 3 - color[u];
				q.push(v);
			} else if (color[v] == color[u])
				return false;
		}
	}

    adj.clear();
    color.clear();

	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l;

    cin >> n;
    while(n != 0){
        cin >> l;

        vector<vector<int>> adj(220);
        vector<int> color(220);
        int u, v;

        for(int i=0; i<l; ++i){
            cin >> u >> v;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        cout << (bfs(0, adj, color) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
        cin >> n;
    }

    return 0;
}