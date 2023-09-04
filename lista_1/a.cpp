#include <bits/stdc++.h>
using namespace std;

bool isGood(const vector<int> &h, const vector<set<int>> &r, int index){
    for(auto &neighbor : r[index]){
        if(h[neighbor] >= h[index]) return false;
    }

    return true;
}

int main(){
    int N, M;
    int goods = 0;

    cin >> N >> M;
    vector<int> height(N+1);

    for(int i=1; i<N+1; ++i){
        cin >> height[i];
    }
    
    vector<set<int>> roads(N+1);

    for (int i=0; i<M; ++i){
        int a, b;

        cin >> a >> b;
        roads[a].insert(b);
        roads[b].insert(a);
    }
    
    for(int i=1; i<N+1; ++i){
        if(isGood(height, roads, i)){
            ++goods;
        }
    }

    cout << goods;
    
    return 0;
}