#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    // The prefix XOR array P has size n+1 (P_0 to P_n)
    vector<long long> P(n + 1);
    P[0] = 0;

    // Use a large base number to generate distinct P_i values.
    // 2^20 is a safe choice since 2^20 < 10^9 and n <= 4*10^5.
    const long long BASE = (1LL << 20); 
    long long distinct_count = 0;

    // 1. Construct the Prefix XOR Array P
    for (int i = 1; i <= n; ++i) {
        if (i == r) {
            // Condition 1: f(l, r) = P[r] ^ P[l-1] = 0 => P[r] = P[l-1]
            P[i] = P[l - 1];
        } else {
            // Condition 2: Ensure distinctness for all other P_i
            // We use the current count as an offset from the BASE
            P[i] = BASE + distinct_count;
            distinct_count++;
        }
    }

    // 2. Adjust the P values that were skipped by P[r]
    // The construction above is slightly simplified. We need to re-scan to ensure 
    // that the intended distinct P values are actually used.

    // A simpler way: just skip the index 'r' in the distinct counter.
    distinct_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == r) {
            P[i] = P[l - 1];
        } else {
            // Find the correct distinct value index to use
            // P_r is NOT a distinct value, so we must adjust the index
            // If i > r, one index was skipped (P_r was set to P_{l-1}), so we start P_r+1 from the P value
            // that *would have been* P_{r-1}'s value if P_r were distinct.
            
            // The distinct P values are P_1, P_2, ..., P_{l-1}, P_l, ..., P_{r-1}, P_{r+1}, ..., P_n
            // The number of distinct values used *before* index i is:
            // (i-1) if i <= r
            // (i-1) - 1 if i > r (because P_r was a duplicate)

            long long index_offset = i - 1;
            if (i > r) {
                index_offset--; // Skip the distinct value that would have gone to P_r
            }
            
            // To ensure P_l, ..., P_{r-1} are distinct from all others, 
            // the value P_{l-1} must also be one of the distinct values, 
            // and the distinct values must also be distinct from 0 (P_0).
            
            // Let's use BASE + i as the distinct value for P_i, and skip the one used for P[l-1] 
            // if l-1 is NOT i. This is getting complex.

            // Let's stick to the simpler construction and check for conflicts:
            // P_i = BASE + i for i != r, P_r = P_{l-1}
            
            if (i == r) {
                 P[i] = P[l - 1];
            } else if (i == l-1) {
                // Ensure P_{l-1} is also a distinct, large value
                P[i] = BASE + i;
            } else if (i < l-1) {
                P[i] = BASE + i;
            } else { // i > l-1 and i != r
                // We must ensure that P_i is distinct from P_{l-1}
                long long current_val = BASE + i;
                if (current_val == P[l-1]) {
                    // This is highly unlikely with a large BASE, but for completeness:
                    current_val++;
                }
                P[i] = current_val;
            }
        }
    }
    
    // Rerun the loop with the simplest, most robust construction:
    // P_i are all distinct, large, and non-zero, except P_r = P_{l-1}.
    distinct_count = 1; // P_0 is 0, so start distinct values from 1
    for (int i = 1; i <= n; ++i) {
        if (i == r) {
            P[i] = P[l - 1];
        } else {
            // Generate a distinct value that is not P[l-1] (if i != l-1) and not 0.
            long long val = BASE + distinct_count;
            if (val == P[l-1] && i != l-1) {
                // Highly unlikely, but increment if it conflicts with the special value P[l-1]
                val++;
            }
            P[i] = val;
            distinct_count++;
        }
    }

    // 3. Calculate the array a
    vector<long long> a(n);
    for (int i = 1; i <= n; ++i) {
        // a_i = P_i ^ P_{i-1}
        a[i - 1] = P[i] ^ P[i - 1];
    }

    // 4. Print the result
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}