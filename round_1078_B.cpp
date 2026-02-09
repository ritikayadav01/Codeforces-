#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;

    vector<long long> v(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += (v[i] / x) * y;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long cur = v[i] + (sum - (v[i] / x) * y);
        ans = max(ans, cur);
    }

    cout << ans << "\n";
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
