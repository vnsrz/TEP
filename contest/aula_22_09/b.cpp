// problem name
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int n, int k){
    int aux, count = 0;
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        if(aux >= k)
            count++;    
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << solve(n,k) << endl;
}