// Payment
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

int solve(int n) {
    int result = 1000;

    while(result < n) {
        result += 1000;
    }
    result = result - n;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    cout << solve(n) << endl;

    return 0;
}