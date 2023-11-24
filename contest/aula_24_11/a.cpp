// Title
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

string solve(int a, int b, int c) {
    int repete = 0;
    if (a == b || a == c) repete++;
    if (b == c) repete++;

    return (repete == 1) ? "Yes" : "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << endl;

    return 0;
}