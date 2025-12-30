#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int x;
        cin>>x;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<mini)mini=arr[i];
            if(arr[i]>maxi)maxi=arr[i];
        }
        if(mini<=x && x<=maxi)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}