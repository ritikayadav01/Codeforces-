#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long  n;
        cin>>n;
        vector<long long>ans;
        long long power=10;
        for(int k=1;k<=18;k++)
        {
            long long p=power+1;
            if(p>n)break;
            if(n%p==0)
            {
                ans.push_back(n/p);
            }
            power*=10;

        }
        if (ans.empty()) {
            cout << 0 << endl;
        } else {
            sort(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (auto x : ans) cout << x << " ";
            cout << endl;
        }

    }
}