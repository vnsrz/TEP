// Multiplication 3
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, int b, int decimal){
    ll res = (a * b);
    ll res2 = a * decimal;
    res2 = res2/100;
    res = res + res2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a;
    int b, decimal;
    char ponto;

    cin >> a >> b >> ponto >> decimal;

    // cout << fixed << setprecision(0);
    cout << solve(a,b,decimal) << endl;
}