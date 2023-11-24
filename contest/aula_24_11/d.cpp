// Pairs - runtime error 46/79
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

ll solve(vector<ll> &numbers, ll k, ll n) {
    ll size = (n*(n-1))/2;
    vector<ll> sums(size);
    ll index = 0;
    ll aux = 0;

    for (ll i=0; i<n-1; ++i) {
        for (ll j=i+1; j<n; ++j) {
            aux = numbers[i] * numbers[j];
            sums[index++] = aux;
        }
    }

    sort(sums.begin(), sums.end());

    // for (auto num : sums)
    //     cout << num << endl;

    return sums[k-1];
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k, aux;
    cin >> n >> k;
    vector<ll> numbers(n);
    
    for (ll i=0; i<n; ++i) {
        cin >> aux;
        numbers[i] = aux;
    }

    cout << solve(numbers, k, n) << endl;

    return 0;
}