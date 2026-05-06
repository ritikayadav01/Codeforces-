#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int x;

        if (b % a == 0) {
            // case 1
            int p = b / a;
            x = b * p;
        } else {
            // case 2
            int g = __gcd(a, b);
            x = b * (a / g);
        }

        cout << x << "\n";
    }
}