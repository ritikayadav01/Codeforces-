
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        bool ok = true;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s[i] != '<' && s[i + 1] != '>') {
                cout << -1 << '\n';
                ok = false;
                break;
            }
        }

        if (ok) {
            int cntL = count(s.begin(), s.end(), '<');
            int cntR = count(s.begin(), s.end(), '>');
            cout << s.size() - min(cntL, cntR) << '\n';
        }
    }
    return 0;
}
