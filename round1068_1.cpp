#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<bool> a(n, false);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                int r = min(n - 1, i + k);
                for (int j = i; j <= r; j++)
                    a[j] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!a[i])
                ans++;

        cout << ans << endl;
    }
}