#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int cy=0,cn=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='Y')cy++;
            else cn++;
        }
        if(cy<=1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}