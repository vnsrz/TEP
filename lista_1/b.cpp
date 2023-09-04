// Cat Snuke and a Voyage
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void printEdges(vector<vector<int>> edges, int size){
    for(int i=1; i<size+1; ++i){
        for(auto edge : edges[i]){
            cout << i << "-" << edge << " ";
        }
        cout << endl;
    }
}

int bfs(const vector<vector<int>> &graph, int s, int target, vector<int> &parent){
    set<int> visited;
    list<int> queue;
    list<int> dist;
    stack<int> shortest_path;

    queue.push_back(s);
    visited.insert(s);
    
    while(!queue.empty()){
        s = queue.front();
        queue.pop_front();
        
        for(auto neighbor : graph[s]){
            if(!visited.contains(neighbor)){
                visited.insert(neighbor);
                queue.push_back(neighbor);
                parent[neighbor] = s;
                if(neighbor == target){
                    while(parent[target] != -1) {
                        shortest_path.push(target);
                        target = parent[target];
                    }
                    return shortest_path.size();
                }
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> boats(n+1);
    vector<int> parent(n+1, -1);
    
    for(int i=1; i<m+1; ++i){
        int a, b;
        cin >> a >> b;
        boats[a].push_back(b);
        boats[b].push_back(a);
    }
    
    bfs(boats, 1, n, parent) == 2? cout << "POSSIBLE": cout << "IMPOSSIBLE";
    cout << endl;

    return 0;
}