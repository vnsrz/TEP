// problem name
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

float solve(int n){
    int total = ceil((float)n/2);
    return (float)total/n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << solve(n) << endl;
}