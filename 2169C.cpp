#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> pre(n, 0);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += arr[i];
            pre[i] = curr;
        }
        int maxi = 0;
        int total = pre[n - 1];

        for (int i = 0; i < n; i++)
        {
            int t1 = 0;
            for (int j = i; j < n; j++)
            {
                int old = pre[j] - (i > 0 ? pre[i - 1] : 0);
                int cs = total - old + (j - i + 1) * (i + j + 2);
                t1 = max(t1, cs);
            }
            maxi = max(maxi, t1);
        }

        maxi = max(maxi, total);

        cout << maxi << endl;
    }
}
