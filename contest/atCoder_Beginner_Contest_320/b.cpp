// Longest Palindrome 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(string s){
    int len = s.length();
    int size = len-1;
    string rev = s;
    string sub, rsub;
    reverse(rev.begin(), rev.end());
    
    if(s == rev) return len;

    for(int j=size; j>1; --j){
        for(int i=0; i<=len-j; ++i){
            sub = s.substr(i, j);
            rsub = sub;
            reverse(rsub.begin(), rsub.end());
            if(sub == rsub) return j;
        }
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;

    cin >> s;

    cout << solve(s) << endl;
    
    return 0;
}