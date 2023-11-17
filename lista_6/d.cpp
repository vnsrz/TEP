// Fennec VS. Snuke
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;
const int oo { 1000000010 };

graph adj;

void dfs(int u, int t, vector<int> &dist) {
	for (auto v : adj[u]) if (v != t){
        dist[v] = dist[u]+1;
		dfs(v, u, dist);
    }
}

string solve(int n) {
    vector<int> f_dist(n+1), s_dist(n+1);
    dfs(0, -1, f_dist);
    dfs(n-1, -1, s_dist);

    int fennec = 0;
    for (int i = 0; i < n; i++) 
        fennec += (f_dist[i] <= s_dist[i]);

    return (2*fennec > n)? "Fennec" : "Snuke";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    adj.resize(n);

    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << solve(n) << endl;

    return 0;
}