#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> cnt(k, 0);
        for (int i = 0; i < n; i++) cnt[i % k] += s[i] - '0';
        bool ok = true;
        for (int r = 0; r < k; r++) {
            if (cnt[r] % 2) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}