#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast modular exponentiation
ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a >>= 1;
        a = a * a % mod;
    }
    return res;
}

// Modular inverse (Fermat's Little Theorem, since p is prime)
ll mod_inv(ll a, ll p) {
    return mod_pow(a, p - 2, p);
}

void solve() {
    int n;
    ll m, p;
    cin >> n >> m >> p;

    // Precompute powers of m up to n/2
    vector<ll> mpow(n / 2 + 1, 1);
    for (int i = 1; i <= n / 2; i++) {
        mpow[i] = mpow[i - 1] * m % p;
    }

    ll expected_correctness = 0;

    for (int k = 1; k <= n; k++) {
        int half = k / 2;
        ll inv = mod_inv(mpow[half], p);  // 1 / m^(floor(k/2))
        ll count = n - k + 1;             // number of subsegments of length k
        expected_correctness = (expected_correctness + count * inv % p) % p;
    }

    ll expected_beauty = expected_correctness * expected_correctness % p;
    cout << expected_beauty << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
