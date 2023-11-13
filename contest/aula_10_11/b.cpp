// Orthogonality
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

// int solve(vector<int> a) {
//     vector<int> c(a.size());
//     for (auto index : a) {
//         int z;
//         z = index
//     }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int x;
    int sum = 0;
    cin >> n;

    vector<int> a(n);

    for (int i=0; i<n; ++i) {
        cin >> x;
        a[i] = x;
    }
    for (int i=0; i<n; ++i) {
        cin >> x;
        sum += a[i] * x;
    }

    cout << ((sum == 0) ? "Yes" : "No") << endl; 
    // cout << solve(a) << endl;

    return 0;
}