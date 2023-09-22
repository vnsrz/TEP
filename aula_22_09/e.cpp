// Get everything
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(vector<int> key_price, vector<vector<int>> boxes, int n, int m, int b){
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, b;
    cin >> n >> m;
    vector<int> key_price(m);
    vector<vector<int>> boxes(m);

    for(int i = 0; i < m; ++i) {
        cin >> key_price[i] >> b;
        for(int j = 0; j < b; ++j) {
            int aux;
            cin >> aux;
            boxes[i].push_back(aux);
        }
    }

    solve(key_price, boxes, n, m, b);
}