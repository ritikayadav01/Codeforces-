#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int ans =0;
        int j=0;
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)len++;
            if(arr[i]==1)len=0;
            if(len==k)
            {
                ans++;
                len=0;
                i++;
                if(i>=n)break;
            }
            while(len>k)
            {
                j++;
                len--;
            }
        }
        cout<<ans<<endl;

    }
}