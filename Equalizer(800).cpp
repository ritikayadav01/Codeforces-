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
        int total=0;
        bool ans=0;
        for(int i=0;i<n;i++)total+=arr[i];
        if(total%2==1)ans=1;
        bool po=0;
        if(total%2==0)
        {
            int num=n*k;
            if(num%2==0)po=1;
        }
        if(ans|| po)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }
}