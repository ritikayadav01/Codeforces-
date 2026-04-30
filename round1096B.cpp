#include<iostream>
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
        int oc=0;
        int co=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')oc++;
            else co++;
        }
        if(oc!=co)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}