#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> Aaa, Baa, Caa, Daa;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x % 6 == 0) Aaa.push_back(x);
            else if (x % 2 == 0) Baa.push_back(x);
            else if (x % 3 == 0) Caa.push_back(x);
            else Daa.push_back(x);
        }

        vector<int> ans;

        for (int x : Aaa) ans.push_back(x);
        for (int x : Baa) ans.push_back(x);
        for (int x : Daa) ans.push_back(x);
        for (int x : Caa) ans.push_back(x);

        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}