#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        int ans = 0;

        for (int k = 1; k <= 20; k++) {
            long long wh = 0, dk = 0;
            for (int i = 0; i < k; i++) {
                long long layer = (1LL << i);
                if (i % 2 == 0) wh += layer;
                else dk += layer;
            }

            bool okkk1 = (wh <= a && dk <= b);
            bool okkk2 = (wh <= b && dk <= a);

            if (okkk1 || okkk2) ans = k;
        }

        cout << ans << endl;
    }
    return 0;
}
