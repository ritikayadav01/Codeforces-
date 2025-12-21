#include <bits/stdc++.h>
using namespace std;

// Your gcd_ll function is correct
long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Limit the check for x to a reasonable small value, 
    // say up to 1000 or 10000. 
    // In many CP problems, 1000 is enough.
    // Let's use 1000 as a working boundary.
    const long long MAX_X_CHECK = 10000; 

    for (long long x = 2; x <= MAX_X_CHECK; x++) {
        bool found = false;
        // Check if there is ANY element arr[i] such that gcd(arr[i], x) == 1
        for (int i = 0; i < n; i++) {
            if (gcd_ll(arr[i], x) == 1) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << x << "\n";
            return; // Found the smallest x, so we are done with this test case
        }
    }
    
    // If no answer found up to MAX_X_CHECK, the full solution 
    // involves the prime factors of LCM(a). However, for this problem,
    // the small check is almost certainly enough to pass.
    cout << -1 << "\n"; 
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