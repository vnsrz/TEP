// 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int n, int x, int y){
    vector<int> perm(n);
    vector<int> visited(n);
    int high = n, low = 1, max = 0;

    for(int i=2; i<n+1; ++i){
        if(i%x == 0){
            while(count(visited.begin(), visited.end(), high)){
                high--;
            }
            perm[i] = high;
            visited.push_back(high--);
            max += perm[i];
        }
        else if(i%y != 0){
            while(count(visited.begin(), visited.end(), low)){
                low++;
            }
            perm[i] = low;
            visited.push_back(low++);
            max -= perm[i];
        }
        else{
            
            perm[i] = 
        }
        cout << perm[i] << " ";
    }

    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y, t;

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n >> x >> y;
        cout << solve(n, x, y) << endl;
    }

    return 0;
}