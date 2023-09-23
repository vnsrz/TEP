// 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, aux=0;
    float a, b, c, more, less, target;

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> a >> b >> c;
        target = (a + b)/2;
        more = (a > b)? a : b;
        less = (a < b)? a : b;
        while(more != target && less != target){
            if((more - c) < target){
                ++aux;
                break;
            }
            more = more - c;
            less = less + c;
            ++aux;
        }
        cout << aux << endl;
        aux = 0;
    }

    return 0;
}