// Play Snuke
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;
const int oo { 1000000010 };

int solve(int n) {
    int a, p, x;
    int menor = oo;

    for (int i=0; i<n; ++i) {
        cin >> a >> p >> x;
        if (x-a > 0)
            if (p < menor)
                menor = p;
    }

    return (menor == oo) ? -1 : menor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}