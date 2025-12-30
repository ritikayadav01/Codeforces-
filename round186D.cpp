#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, const vector<int>& p, int n) {
    int total = 0;
    for (int x : a) total += x;

    for (int st = 0; st < total; st++) {
        int per = p[st % n];
        if (a[per] > 0) {
            a[per]--;
        }
        else if (a[0] > 0) {
            a[0]--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 0; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> per(n);
        iota(per.begin(), per.end(), 1);

        int ans = 0;

        do {
            if (check(a, per, n)) {
                ans++;
            }
        } while (next_permutation(per.begin(), per.end()));

        cout << ans << '\n';
    }
    return 0;
}
