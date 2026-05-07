#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &x : a) cin >> x;

    cout << (k == 1 ? *min_element(a.begin(), a.end())
          : k == 2 ? max(a[0], a[n-1])
                   : *max_element(a.begin(), a.end()));
}