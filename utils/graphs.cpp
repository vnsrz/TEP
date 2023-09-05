#include <bits/stdc++.h>
using namespace std;

void printEdges(vector<vector<int>> edges, int size){
    for(int i=1; i<size+1; ++i){
        for(auto edge : edges[i]){
            cout << i << "-" << edge << " ";
        }
        cout << endl;
    }
}