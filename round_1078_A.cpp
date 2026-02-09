#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
        int n , w;
        cin>>n>>w;
        int ans =n%w;
        ans+=(n/w)*(w-1);
        cout<<ans<<endl;
        
     }
 }