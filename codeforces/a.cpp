//
#include <bits/stdc++.h>
using namespace std;

string solve(string str){
    int len = str.length();
    int count = 0;
    if(str == "cba") return "YES";

    for(int i=0; i<len; ++i){
        for(int k=i; k<len; ++k){
            if(str[i] > str[k]) count++;
        }
    }
    if(count > 1) return "NO";
    return "YES";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        cout << solve(str) << endl;
    }
}