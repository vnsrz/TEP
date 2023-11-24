// Title
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
using graph = vector<vector<int>>;

void solve(map<string, int> words, int max) {
    for (auto word : words) {
        if (word.second == max)
            cout << word.first << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    map<string, int> words;
    int most_occurent = 0;
    string in;

    for (int i=0; i<n; ++i) {
        cin >> in;
        if (words.count(in)) {
            words[in] += 1;
            most_occurent = max(most_occurent, words[in]);
        } else {
            words.insert(make_pair(in,0));
        }
    }

    solve(words, most_occurent);

    return 0;
}