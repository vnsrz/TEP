#include <bits/stdc++.h>
using namespace std;

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