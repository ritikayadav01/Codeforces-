#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool s6 = 0, s5 = 0, s2 = 0, s20 = 0;

        for (int i = 0; i < n; i++) {
            if (i + 4 <= n) {
                string sub = s.substr(i, 4);
                if (sub == "2026") {
                    s6 = 1;
                    break;
                }
                if (sub == "2025") s5 = 1;
            }
            // if (i + 3 <= n) {
            //     if (s.substr(i, 3) == "202") s2 = 1;
            // }
            // if (i + 2 <= n) {
            //     if (s.substr(i, 2) == "20") s20 = 1;
            // }
        }

        if (s6 || !s5) cout << 0 << "\n";
        else if (s5) cout << 1 << "\n";
        // else if (s2) cout << 1 << "\n";
        // else if (s20) cout << 2 << "\n";
        else cout << 0 << "\n";
    }
}
