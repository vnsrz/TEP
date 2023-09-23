// The Corridor or There and Back Again
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(const vector<vector<int>> &rooms){
    int k=0;
    while(true){
        if(rooms[k][])
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, ans;
    vector<vector<int>> rooms(200);

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n;
        for(int j=0; j<n; ++j){
            int d, s;
            cin >> d >> s;
            rooms[d][j] = s;
        }
        ans = solve(rooms);
    }

    return 0;
}