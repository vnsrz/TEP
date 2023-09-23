// 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int l, int r){
    int a, b;

    for(a=r; a>1; --a){
        for(b=2; b<r; ++b){
            if((a+b) <= r && (a+b) >= l && gcd(a,b) != 1){
                cout << a << " " << b;
                return;
            }
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r, t;

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> l >> r;
        solve(l, r);  
    }

    return 0;
}