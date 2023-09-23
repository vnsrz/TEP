// 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef struct position{
    int observer;
    int person;
    int x;
    int y;
}position;

typedef struct person_pos{
    int x;
    int y;
}person_pos;

int solve(vector<position> pos, int n){
    vector<person_pos> pp(n+1);
    for(auto p : pos){
        if(p.observer == 1){
            pp[p.person].x = p.x;
            pp[p.person].y = p.y;
        }
    }

    for(int i=1; i<n+1; ++i){
        cout << pp[i].x << " " << pp[i].y << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<position> pos(m);

    for(int i=0; i<m; ++i){
        cin >> pos[i].observer >> pos[i].person >> pos[i].x >> pos[i].y;
    }

    solve(pos, n);

    return 0;
}