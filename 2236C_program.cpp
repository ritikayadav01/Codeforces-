#include <bits/stdc++.h>
using namespace std;

map<pair<long long,long long>, long long> dp;
long long x;

long long solve(long long a, long long b)
{
    if(a == b) return 0;

    if(dp.count({a,b}))
        return dp[{a,b}];

    // Make them equal using only +1 operations
    long long ans = abs(a - b);

    if(x > 1)
    {
        if(a > b)
            ans = min(ans, 1 + solve(a / x, b));

        if(b > a)
            ans = min(ans, 1 + solve(a, b / x));
    }

    return dp[{a,b}] = ans;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long a, b;
        cin >> a >> b >> x;

        dp.clear();

        cout << solve(a, b) << '\n';
    }
}