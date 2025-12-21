#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int n = t.size(), m = s.size();

        unordered_map<char,int> mp1, mp2;
        for (char c : t) mp1[c]++;
        for (char c : s) mp2[c]++;

        bool bad = false;
        for (auto &p : mp2)
            if (mp1[p.first] < p.second) bad = true;

        if (bad) {
            cout << "Impossible\n";
            continue;
        }
        vector<char> keys;
        for (auto &p : mp2) keys.push_back(p.first);

        for (char ch : keys) {
            while (mp2[ch] > 0) {
                mp2[ch]--;
                mp1[ch]--;
                if (mp1[ch] == 0) mp1.erase(ch);
            }
        }
        string c = "";
        for (auto &p : mp1)
            c.append(p.second, p.first);

        sort(c.begin(), c.end());
        int k = 0, j = 0;
        while (k < m && j < (int)c.size()) {
            if (c[j] >= s[k]) {
                c.insert(c.begin() + j, s[k]);
                k++;
                j++;
            } else {
                j++;
            }
        }

        while (k < m) c += s[k++];

        cout << c << "\n";
    }
    return 0;
}
