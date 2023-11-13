// Title
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

string solve(int x, int y) {
    if (abs(x - y) >= 3) return "No";
    return "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y;
    cin >> x >> y;

    cout << solve(x,y) << endl;

    return 0;
}