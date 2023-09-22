//
#include <bits/stdc++.h>
using namespace std;

int solve(string str, int n, int k){
    int steps = 0, aux = 0;
    bool has_black = false;
    int last_b = 0;

    for(int i=0; i<n; i++, aux++){
        if(str[i] == 'B'){
            if((i-last_b) < k){
                steps++;
            }
            last_b = i;
            aux = 0;
        }
        if(aux == k and has_black){
            aux = 0;
            steps++;
            has_black = false;
        }
        if(aux < k and (i+1) >= n and has_black){
            steps++;
        }
    }
    return steps;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;
    string str;

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> k >> str;
        cout << solve(str, n, k) << endl;
    }
    
}