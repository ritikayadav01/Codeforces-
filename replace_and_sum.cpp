#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n,q;
        cin >> n >> q;

        vector<long long>a(n),b(n),temp(n);

        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        for(int i=0;i<n;i++)
            temp[i]=max(a[i],b[i]);

        for(int i=n-2;i>=0;i--)
            temp[i]=max(temp[i],temp[i+1]);

        vector<long long>pre(n+1,0);

        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+temp[i];

        while(q--)
        {
            int l,r;
            cin>>l>>r;

            cout<<pre[r]-pre[l-1]<<" ";
        }

        cout<<"\n";
    }
}