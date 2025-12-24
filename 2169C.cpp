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

        long long prefixSum = 0;   // sum of elements so far
        long long totalSum = 0;    // sum of whole array

        long long minValue = 0;    // minimum F(k) seen so far
        long long bestGain = 0;    // best gain we can achieve

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            prefixSum += x;
            totalSum += x;

            // This is F(r)
            long long currentValue = 1LL * i * (i + 1) - prefixSum;

            // Update best gain
            bestGain = max(bestGain, currentValue - minValue);

            // Update minimum F(k) so far
            minValue = min(minValue, currentValue);
        }

        // Final answer
        cout << totalSum + bestGain << "\n";
    }

    return 0;
}
