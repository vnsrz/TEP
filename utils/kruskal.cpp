#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;
const int oo { 1000000010 };

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

int kruskal(int N, vector<edge>& es) {
    sort(es.begin(), es.end());

    int cost = 0;
    DSU dsu(N);

    for (auto [w, u, v] : es)
        if (dsu.unite(u, v))
            cost += w;

    return cost;
}

// Minimum spanning forest
int msf(int k, int N, vector<edge>& es) {
    sort(es.begin(), es.end());

    int cost = 0, cc = N;
    DSU dsu(N);

    for (auto [w, u, v] : es){
        if (dsu.unite(u, v)){
            cost += w;
            if (--cc == k)
                return cost;
        }
    }

    return cost;
}

// Second best MST
pair<int, vector<int>> kruskal_2(int N, vector<edge>& es, int blocked = -1) {
    vector<int> mst;
    DSU dsu(N);
    int cost = 0;
    for (int i = 0; i < (int) es.size(); ++i) {
        auto [w, u, v] = es[i];
        if (i != blocked and dsu.unite(u,v)) {
            cost += w;
            mst.emplace_back(i);
        }
    }
    return { (int) mst.size() == N - 1 ? cost : oo, mst };
}

int second_best(int N, vector<edge>& es) {
    sort(es.begin(), es.end());
    auto [_, mst] = kruskal_2(N, es);
    int best = oo;
    for (auto blocked : mst) {
        auto [cost, __] = kruskal_2(N, es, blocked);
        best = min(best, cost);
    }
    return best;
}