// Teleporter
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;

vector<int> visited(1000000);
vector<int> destination(1000000);
vector<ll> cycle;
int step = 0;
int position = 0;

void dfs(int u) {
	if (visited[u]){
        step = visited[u]-1;
        return;
    }

	visited[u] = ++position;
    cycle.push_back(u);

	dfs(destination[u]);
}

int solve(ll n, ll k) {
    int a;

    for (ll i=1; i<=n; ++i) {
        cin >> a;
        destination[i] = a;
    }

    dfs(1);

    int cycle_size = cycle.size();
    if (k>=cycle_size)
        return cycle[step + (k-step)%(cycle_size-step)];

    return cycle[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    cout << solve(n,k) << endl;

    return 0;
}