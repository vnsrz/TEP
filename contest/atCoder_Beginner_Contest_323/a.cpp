// Weak Beats 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;

bool solve(string s) {
    for(int i=2; i<=16; i+=2)
        if(s[i] == '1') return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "x", t;
    cin >> t;
    s.append(t);

    string ans = solve(s)? "Yes" : "No";
    cout << ans << endl;

    return 0;
}