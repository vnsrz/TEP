// Judge status summary
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

void solve(vector<string> &s) {
    vector<int> result(4,0);
    for (string ans : s) {
        if (ans == "AC")
            result[0]++;
        if (ans == "WA")
            result[1]++;
        if (ans == "TLE")
            result[2]++;
        if (ans == "RE")
            result[3]++;
    }
    cout << "AC x " << result[0] << endl;
    cout << "WA x " << result[1] << endl;
    cout << "TLE x " << result[2] << endl;
    cout << "RE x " << result[3] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<string> s(n);

    for (int i=0; i<n; ++i) {
        cin >> s[i];
    }

    solve(s);

    return 0;
}