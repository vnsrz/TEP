// Disjoint set of common divisors
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
using ll = long long;

set<int> solve(int a, int b){
    vector<int> divisors;
    set<int> res;
    
    for (auto i = 2; i*i <= b; i++)
    {
        if ( !(a % i) && !(b % i) )
            divisors.push_back(i);
    }

    vector<ii> allPossi;
    for (auto i = 0; i < (int) (divisors.size() - 1); i++)
    {
        for (auto j = 1; j < (int) (divisors.size()); j++) {
            allPossi.push_back({divisors[i], divisors[j]});
        }
        
    }
    for (auto [xi, yi] : allPossi) {
        if ( gcd(xi, yi) == 1 ) {
            res.insert(xi); 
            res.insert(yi);
        }
    }

    res.insert(1);

    return res;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    set<int> res = solve(a, b);

    // for ( auto el : res )
    //     cout << el << " ";

    cout << res.size() << endl;
}