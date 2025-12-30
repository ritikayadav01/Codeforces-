#include <bits/stdc++.h>
using namespace std;

// Memo table
map<pair<vector<long long>, long long>, long long> dp;

long long dfs(vector<long long> arr, long long x) {
    if (arr.size() == 1) {
        return x;
    }
    auto key = make_pair(arr, x);
    if (dp.count(key)) {
        return dp[key];
    }

    vector<long long> a1 = arr;
    long long v1 = a1[0];
    a1.erase(a1.begin());
    long long r1 = dfs(a1, x + v1);
    vector<long long> a2 = arr;
    long long v2 = a2[1];
    a2.erase(a2.begin() + 1);
    long long r2 = dfs(a2, x - v2);

    return dp[key] = max(r1, r2);
}

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp.clear();  
    cout << dfs(a, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
