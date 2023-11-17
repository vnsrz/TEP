// Discount
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

double solve(ll a, ll b) {
    double result = 100 - ((static_cast<double>(b)/a) * 100);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b;
    cin >> a >> b;

    cout << setprecision(15) << solve(a, b) << endl;

    return 0;
}