// 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using set_c = unordered_set<char>;

int solve(int m, vector<string> s){
    // set_c set1(s[0].begin(), s[0].end());
    // set_c set2(s[1].begin(), s[1].end());
    set_c candidates;
    int time, lowest = m+1;
    char b;

    for (char c : s[2]) {
        if (s[0].find(c) >= 0 && s[1].find(c) >= 0) {
            candidates.insert(c);
        }
    }

    if(candidates.empty()) return -1;

    for(char c : candidates){
        time = max(s[0].find(c), max(s[1].find(c), s[2].find(c)));
        if(time < lowest){
            lowest = time;
            b = c;
        }
    }

    cout << b << endl;

    return lowest;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    vector<string> s(3);

    cin >> m >> s[0] >> s[1] >> s[2];
    
    cout << solve(m, s) << endl;

    return 0;
}