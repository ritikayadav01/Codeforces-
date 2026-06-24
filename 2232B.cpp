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
        vector<long long >h(n);
        long long ans  =INT_MAX;
        long long  sum=0;
        for(int i=0;i<n;i++ )cin>>h[i];
        for(int i=0;i<n;i++)
        {
            sum+=h[i];
            ans=min(ans,sum/(i+1));
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}