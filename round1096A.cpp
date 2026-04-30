#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        int oc=0;
        if(x%2==1)oc++;
        if(y%2==1)oc++;
        if(oc==2)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}