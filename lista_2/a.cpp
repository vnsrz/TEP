// Hopscotch addict
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<set<int>>;

void dfs_visit(const Graph &g, int parent, int v, int depth_max, int c_depth, set<int> &reached){
    if(c_depth == depth_max){
        reached.insert(v);
        return;
    }

    for(auto w : g[v])
        if(w != parent)
            dfs_visit(g, v, w, depth_max, c_depth+1, reached);
}

set<int> dfs(const Graph &g, int start, int max_depth){
    set<int> visited;
    set<int> reached;
    dfs_visit(g, -1, start, max_depth, 0, reached);
    return reached;
}

int bfs(Graph g, int s, int t){
    set<int> visited; int depth;
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    
    while(not q.empty()){
        depth = q.front().second;
        auto v = q.front().first; q.pop();

        if(v == t)
            return depth;
        
        for(auto neighbor : g[v]){
            if(not visited.count(neighbor)){
                visited.insert(neighbor);
                q.emplace(neighbor, depth+1);
            }
        }
    }

    return -1;

}

int solve(Graph g, int s, int t, int n){
    Graph h(g.size());
    queue<int> q;
    set<int> edges;
    q.push(s);

    for(int i=1; i<n; i++){
        edges = dfs(g, i, 3);
        h[i] = edges;
    }

    for(int i=1; i<n; ++i){
        for(auto v : h[i]){
            cout << i  << "->" << v << " ";
        }
    }
    cout << endl;
    for(int i=1; i<n; ++i){
        for(auto v : g[i]){
            cout << i  << "->" << v << " ";
        }
    }

    return bfs(h, s, t);

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

    cout << solve(graph, s, t, n+1) << endl;
    
}