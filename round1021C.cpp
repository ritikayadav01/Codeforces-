#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long a1 = a[0];
        long long a2 = a[1];

        // Maximum k that works
        long long ans = max(a1, a2 - a1);

        cout << ans << '\n';
    }

    return 0;
}
