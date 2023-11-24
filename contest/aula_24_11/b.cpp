// Title
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

string solve(int n) {
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (a%2 == 0 && a%3 != 0 && a%5 != 0)
            return "DENIED";
    }
    return "APPROVED";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}