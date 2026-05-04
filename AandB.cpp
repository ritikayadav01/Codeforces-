#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // Prefix arrays
    vector<int> costMakeA_Left(n, 0); // cost to fix left part if we want 'a' block
    vector<int> costMakeB_Left(n, 0); // cost to fix left part if we want 'b' block
    vector<int> countA_Left(n, 0);    // number of 'a' till i

    countA_Left[0] = (s[0] == 'a');

    for (int i = 1; i < n; i++) {
        countA_Left[i] = countA_Left[i - 1];
        costMakeA_Left[i] = costMakeA_Left[i - 1];
        costMakeB_Left[i] = costMakeB_Left[i - 1];

        if (s[i] == 'a') {
            countA_Left[i]++;
            // this 'a' needs to move left across all 'b's before it
            costMakeB_Left[i] += (i + 1 - countA_Left[i]);
        } else {
            // this 'b' needs to move right across all 'a's before it
            costMakeA_Left[i] += countA_Left[i];
        }
    }

    // Suffix arrays
    vector<int> costMakeA_Right(n, 0);
    vector<int> costMakeB_Right(n, 0);
    vector<int> countA_Right(n, 0);

    countA_Right[n - 1] = (s[n - 1] == 'a');

    for (int i = n - 2; i >= 0; i--) {
        countA_Right[i] = countA_Right[i + 1];
        costMakeA_Right[i] = costMakeA_Right[i + 1];
        costMakeB_Right[i] = costMakeB_Right[i + 1];

        if (s[i] == 'a') {
            countA_Right[i]++;
            costMakeB_Right[i] += (n - i - countA_Right[i]);
        } else {
            costMakeA_Right[i] += countA_Right[i];
        }
    }

    int ans = INF;

    for (int i = 0; i < n; i++) {
        // Option 1: make all 'a' one block
        int costA = costMakeA_Left[i] + costMakeA_Right[i];

        // Option 2: make all 'b' one block
        int costB = costMakeB_Left[i] + costMakeB_Right[i];

        ans = min({ans, costA, costB});
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}