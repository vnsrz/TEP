//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pontos(int linha, int coluna){
    if(linha == 0 || linha == 9 || coluna == 0 || coluna == 9)
        return 1;
    if(linha == 1 || linha == 8 || coluna == 1 || coluna == 8)
        return 2;
    if(linha == 2 || linha == 7 || coluna == 2 || coluna == 7)
        return 3;
    if(linha == 3 || linha == 6 || coluna == 3 || coluna == 6)
        return 4;
    return 5;
}

int solve(){
    string linha;
    int points = 0;

    for(int i=0; i<10; i++){
        cin >> linha;
        for(int k=0; k<10; k++){
            if(linha[k] == 'X'){
                points += pontos(i, k);
            }
        }
    }
    return points;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    for (int i = 0; i < t; i++){
        cout << solve() << endl;
    }

    return 0;
    
}