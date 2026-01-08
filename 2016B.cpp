#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> f(n + 2, 0);
        for (int x : a) {
            if (x <= n) f[x]++;
        }

        int m = 0;
        while (m <= n && f[m] > 0) m++;

        cout << min(m, k - 1) << '\n';
    }
    return 0;
}
