// 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;

    cout << fixed << setprecision(0) << pow(a,b) + pow(b,a) << endl;

    return 0;
}