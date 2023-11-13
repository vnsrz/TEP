// ABC tournament
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;

int solve(vector<int> rating) {
    ii winner1 = {0,0}, winner2 = {0,0};
    for (int i=0; i<(int)rating.size()/2; ++i) {
        if (rating[i] > winner1.first) {
            winner1.first = rating[i];
            winner1.second = i;
        }
    }
    for (int i=(rating.size()/2); i<(int)rating.size(); ++i) {
        if (rating[i] > winner2.first) {
            winner2.first = rating[i];
            winner2.second = i;
        }
    }

    if (winner1.first < winner2.first) {
        return winner1.second;
    }
    return winner2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    vector<int> rating(pow(2,n));

    for (int i=0; i<pow(2,n); ++i) {
        cin >> x;
        rating[i] = x;
    }

    cout << solve(rating)+1 << endl;

    return 0;
}