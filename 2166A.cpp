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
         string s;
         cin>>s;
         int ans=0;
         char ch=s[n-1];
         for(int i=n-2;i>=0;i--)
         {
            if(s[i]!=ch)ans++;
         }
         cout<<ans<<endl;

    }
}