// Hopscotch addict
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<set<int>>;

int solve(const Graph &g, int s, int t) {
    queue<int> q;
    set<int> visited, queued;
    int count = 1, depth = 1;

    for (auto edge : g[s])
        q.push(edge);
    q.push(0);
    
    visited.insert(s);

    while (not q.empty()) {
        int v = q.front(); q.pop();
        if (v) {
            if (depth == 3) {
                if (v == t) return count;
                if (visited.count(v)) continue;
                visited.insert(v);
            }
            
            for (auto neighbor : g[v]) {
                if(not queued.count(neighbor)){
                    q.push(neighbor);
                    queued.insert(neighbor);
                }
            }
        } else {
            if (q.empty()) return -1;
            
            q.push(0);
            queued.clear();

            if (depth == 3) {
                depth = 1; 
                count++;
            } else depth++;
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u, v, s, t;

    cin >> n >> m;
    Graph graph(n+1);

    for (int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].insert(v);
    }

    cin >> s >> t;

    cout << solve(graph, s, t) << endl;
    
}