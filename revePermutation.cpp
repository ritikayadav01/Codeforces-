#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);  // ✅ FIX #1
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({arr[i], i});

        sort(v.begin(), v.end(), greater<pair<int,int>>());

        int st = -1, en = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] != v[i].first) {
                st = i;
                en = v[i].second;
                break;
            }
        }

        if (st != -1 && en != -1) {
            if (st > en) swap(st, en);  // ✅ FIX #2
            reverse(arr.begin() + st, arr.begin() + en + 1);
        }

        for (int x : arr) cout << x << " ";
        cout << endl;
    }
}