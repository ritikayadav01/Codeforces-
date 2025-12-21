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

        if (n % 2 == 1) {
            cout << 0 << "\n";
        } else {
            // n = 2*(c + 2w)
            int half = n / 2;
            cout << (half / 2) + 1 << "\n";
        }
    }
    return 0;
}
