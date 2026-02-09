#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// We use a bitset or a simple frequency array to find the intersection of characters.
// Since there are only 26 lowercase letters, a bitmask (int) is very efficient.

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> strips(k);
    for (int i = 0; i < k; ++i) cin >> strips[i];

    // Pre-calculate which characters are available at each position 0...n-1
    vector<int> masks(n, 0);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < k; ++i) {
            masks[j] |= (1 << (strips[i][j] - 'a'));
        }
    }

    // Find all divisors of n and sort them to find the minimum d first
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());

    for (int d : divisors) {
        bool possible = true;
        string period = "";
        
        for (int i = 0; i < d; ++i) {
            int common_chars = (1 << 26) - 1; // Start with all bits set
            for (int j = i; j < n; j += d) {
                common_chars &= masks[j];
            }
            
            if (common_chars == 0) {
                possible = false;
                break;
            } else {
                // Pick the first available common character
                for (int c = 0; c < 26; ++c) {
                    if ((common_chars >> c) & 1) {
                        period += (char)('a' + c);
                        break;
                    }
                }
            }
        }

        if (possible) {
            string result = "";
            while (result.length() < n) result += period;
            cout << result << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}