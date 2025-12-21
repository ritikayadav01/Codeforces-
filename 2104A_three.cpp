#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if ((a + b + c) % 3 != 0) {
            cout << "NO\n";
            continue;
        }

        long long x = (a + b + c) / 3;
        cout << (b <= x ? "YES\n" : "NO\n");
    }
    return 0;
}
