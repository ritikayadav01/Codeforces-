#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1), b(n + 1), pref(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = (i % 2 ? a[i] : -a[i]);
        }

        pref[0] = 0;
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + b[i];

        // Coordinate compression
        vector<ll> all = pref;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        auto get = [&](ll x) {
            return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
        };

        Fenwick ft(all.size());

        ll ans = 0;

        for (int i = 0; i <= n; i++) {
            int id = get(pref[i]);
            ans += ft.query(id - 1); // count smaller prefix
            ft.update(id, 1);
        }

        cout << ans << "\n";
    }

    return 0;
}