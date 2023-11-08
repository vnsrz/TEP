// Multiplication 2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000000000000000000

ll solve(int n){
    ll x, prd = 1, check;
    bool zero_check = false;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(x == 0) return 0;

        if(not zero_check){
            check = MAX;
            cout << check;
            if(prd > check){
                prd = -1;
                zero_check = true;
            }else
                prd = prd * x;        
        }
    }

    return prd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}