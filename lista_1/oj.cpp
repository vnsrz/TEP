//oj 11094
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int,int>;

int main(){
    int m, n;
    cin >> m >> n;
    vector<string> map;
    for(int i=0; i<m; ++i){
        cin >> map[i];
    }
    int x, y;
    cin >> x >> y;

    auto land = map[x][y];
    vector<ii> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    for(auto[dx,dy] : dirs){
        auto u = x+dx, v = (y+dy)%n;
        if(0<=u and u<m){
            // conta territorio
        }
    }
}