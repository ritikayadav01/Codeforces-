#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(long long  num){
    string t=to_string(num);
    int n=t.size();
    for(int i=0;i<t.size()/2;i++)
    {
        if(t[i]!=t[n-i-1])return 0;

    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long  n;
        cin>>n;
        long long  a=-1;
        long long  b=-1;
        for(int i=0;i<=n;i++)
        {
            long long  ta=i;
            long long  tb=n-i;
            int f=solve(ta);
            if(f)a=ta;else a=-1;
            if(f==1 && tb%12==0)b=tb;else b=-1;
            if(a!=-1 && b!=-1)break;
        }
        if(a!=-1 && b!=-1)cout<<a<<" "<<b<<endl;
        else cout<<-1<<endl;
    }
}