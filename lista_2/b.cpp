// Connectivity
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;

typedef struct DSU{
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) 
            return false;
        if (size[a] < size[b]) 
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
}DSU;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, l, u, v;
    
    cin >> n >> k >> l;
    
    map <ii, int> visited;
    DSU roads(n+1);
    DSU rails(n+1);


    for (int i = 0; i < k; i++){ // roads
        cin >> u >> v;
        roads.unite(u,v);
    }

    for(int i=0; i<l; ++i){ // rails
        cin >> u >> v;
        rails.unite(u,v);
    }

    for(int i=1; i<n+1; ++i){
        ++visited[make_pair(roads.find(i), rails.find(i))];
    }
    
    for(int i=1; i<n+1; ++i){
        cout << visited[make_pair(roads.find(i), rails.find(i))] << " ";
    }
    cout << endl;

    return 0;
}