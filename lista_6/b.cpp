// Party
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

graph adj;

int dfs(int u, vector<bool> &visited) {
	if (u < 0 || u >= (int)adj.size()) return 0;
    
    int maxHeight = 0;
    visited[u] = true;

    for (int v : adj[u]) {
        int childHeight = dfs(v, visited);
        maxHeight = max(maxHeight, childHeight);
    }

    return maxHeight + 1;
}

int solve(int n) {
    vector<bool> visited(n+1, false);
    int max_height = 0;
    for(int i=1; i<n+1; ++i){
        int height = 0;
        if (!visited[i]) {   
            height = dfs(i, visited);
            max_height = max(height, max_height);
            // cout << height << endl;
        }
    }
    return max_height;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    adj.resize(n+1);

    for (int i=1; i<n+1; ++i) {
        int parent;
        cin >> parent;
        if (parent != -1)
            adj[parent].push_back(i);
    }

    cout << solve(n) << endl;

    return 0;
}