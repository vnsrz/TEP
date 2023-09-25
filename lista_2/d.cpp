// Shortest path of the king 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(string s, string t){
    int dist_x = abs(s[0]-t[0]);
    int dist_y = abs(s[1]-t[1]);

    cout << max(dist_x, dist_y) << endl;

    while (s != t) {
        if (s[0] < t[0]) {
            cout << "R";
            s[0] += 1;
        }

        if (s[0] > t[0]) {
            cout << "L";
            s[0] -= 1;
        }

        if (s[1] < t[1]) {
            cout << "U";
            s[1] += 1;

        }
        
        if (s[1] > t[1]) {
            cout << "D";
            s[1] -= 1;
        }

        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    solve(s, t);

    return 0;
}