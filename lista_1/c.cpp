// Students and Shoelaces
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(vector<set<int>> &edges, int size){
    int aux = 0;
    int count = 0;
    vector<set<int>> copy = edges;

    for(int i=1; i<size+1; ++i){
        if(copy[i].size() == 1){
            aux = *copy[i].begin();
            edges[i].extract(aux);
            edges[aux].extract(i);
            ++count;
        }
    }
    return count;
}

void printEdges(vector<set<int>> edges, int size){
    for(int i=1; i<size+1; ++i){
        for(auto edge : edges[i]){
            cout << i << "-" << edge << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, ans = 0;
    cin >> n >> m;
    vector<set<int>> laces(n+1);

    for(int i=1; i<m+1; ++i){
        int a, b;
        cin >> a >> b;
        laces[a].insert(b);
        laces[b].insert(a);
    }

    while(solve(laces, n)){
        ++ans;
    }

    cout << ans << endl;

    return 0;
}