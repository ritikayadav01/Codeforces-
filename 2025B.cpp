#include <bits/stdc++.h>
using namespace std;

void solve() {
    string r;
    cin >> r;

    for (char c : r) {
        assert(c == 's' || c == 'u');
    }

    int n = r.size();
    int ops = 0;

    if (r[0] == 'u') {
        r[0] = 's';
        ops++;
    }

    if (r[n - 1] == 'u') {
        r[n - 1] = 's';
        ops++;
    }

    for (int i = 1; i < n - 1; i++) {
        if (r[i] == 'u' && r[i + 1] == 'u') {
            r[i + 1] = 's';
            ops++;
        }
    }

    int cnt = 0;
    for (char c : r) {
        if (c == 's') cnt++;
    }

    if (cnt < 2) {
        ops += (2 - cnt);
    }

    cout << ops << '\n';
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
