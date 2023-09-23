// Go to school
#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
using ll = long long;

void solve(vector<ii> a){
    sort(a.begin(), a.end());
    for(auto element : a) {
        cout << element.second << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, aux;
    cin >> n;
    vector<ii> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> aux;
        a[i] = {aux, i+1};
    }

    solve(a);
}