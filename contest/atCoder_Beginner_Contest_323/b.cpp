// Round-Robin Tournament 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;

bool comp(const ii &a, const ii &b){
    if (a.first > b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    return false;
}

void solve(int n) {
    string s;
    vector<ii> rank(n);

    for(int i=0; i<n; ++i){
        cin >> s;
        rank[i] = make_pair(count(s.begin(),s.end(),'o'), i+1);
    }

    sort(rank.begin(), rank.end(), comp);

    for(int i=0; i<n; ++i){
        cout << rank[i].second << " ";
    }
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    solve(n);

    return 0;
}