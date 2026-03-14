#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool check(ll x, int n, int m, ll l, const vector<int>& a) {
    if (x >= l) return true;
    
    // The total amount of danger that can be "absorbed" by the end of the night
    // is m * x (each animatronic holds at most x).
    // Each flashlight use at time a_i can "wipe" at most x danger.
    // However, a flash at time a_i can't wipe more than a_i danger 
    // because only a_i seconds have passed.
    
    ll total_cleared = 0;
    for (int i = 0; i < n; ++i) {
        total_cleared += min((ll)a[i], x);
    }
    
    return (total_cleared + (ll)m * x >= l);
}

void solve() {
    int n, m;
    ll l;
    if (!(cin >> n >> m >> l)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll low = 0, high = l, ans = l;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, n, m, l, a)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
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