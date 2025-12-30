#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<bool> check1(n, true), check2(n, true);
        for (int x = 0; x < n; x++) {
            for (int t = 0; t < n; t++) {
                if (a[t] >= b[(t + x) % n]) {
                    check1[x] = false;
                    break;
                }
            }
        }
        for (int y = 0; y < n; y++) {
            for (int t = 0; t < n; t++) {
                if (b[t] >= c[(t + y) % n]) {
                    check2[y] = false;
                    break;
                }
            }
        }

        long long c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            c1 += check1[i];
            c2 += check2[i];
        }

        cout << 1LL * n * c1 * c2 << endl;
    }
    return 0;
}
