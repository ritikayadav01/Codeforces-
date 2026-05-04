#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int n = x + y;
        int d = y - x;

        // Impossible cases
        if ((x == 0 && n % 2 == 0) || (n / 2 < x)) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int mm = 2 * x + (d % 2);

        // Build chain
        for (int i = 2; i <= mm; i++) {
            cout << i - 1 << " " << i << "\n";
        }

        // Attach remaining nodes
        for (int i = mm + 1; i <= n; i++) {
            cout << mm << " " << i << "\n";
        }
    }
}