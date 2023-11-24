// Payment -- incomplete
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

ll solve(ll n) {
    // vector<ll> notes(pow(10, 100) + 1);

    // iota(notes.begin(), notes.end(), 0);
    // transform(notes.begin(), notes.end(), notes.begin(),
    //                [](ll x) { return static_cast<ll>(pow(10, x)); });

    // generate(notes.begin(), notes.end(), [i = 100]() mutable {
    //     return static_cast<ll>(pow(10, i--));
    // });

    ll notes_qtt = 0;
    ll remaining = n;
    ll index = 0, aux = 0;

    while (n > 1) {
        aux++;
    }
    ll curr_note = pow(10, aux);
    
    while (remaining > 0) {
        remaining -= curr_note;
        notes_qtt++;
        if (remaining < curr_note/2 && aux > 0) {
            curr_note = pow(10, --aux);
        }
    }
    
    return notes_qtt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}