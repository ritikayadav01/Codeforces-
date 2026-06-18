#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x1,x2,k;
        cin>>n>>x1>>x2>>k;
        if(n<=3)cout<<1<<endl;
        else 
        {
        int ans=min(abs(x1-x2),n-abs(x1-x2))+k;
        cout<<ans<<endl;
        }
    }
}