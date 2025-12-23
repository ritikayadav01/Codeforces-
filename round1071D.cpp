#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int N = 1 << n;
        vector<int> p;

        for (int i = 0; i < N; ) {
            // largest power of two <= i
            int msb = 1;
            while ((msb << 1) <= i) msb <<= 1;

            int r = i | (msb - 1);

            for (int x = r; x >= i; x--) {
                p.push_back(x);
            }
            i = r + 1;
        }

        for (int x : p) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
