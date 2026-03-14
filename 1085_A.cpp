#include<iostream>
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
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')oc++;
        }
        if(oc==n)
        {
            if(n%2==0)cout<<n-((n/2)-1)<<" "<<n;
            else cout<<n-(n/2)<<" "<<n;
        }
        else 
        {
            for(int i=1;i<n-1;i++)
            {
                if(s[i-1]=='1' && s[i+1]=='1')
                {
                    s[i]='1';
                }
            }
            int maxi =0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')maxi++;
            }
            int mini=0;
            for(int i=1;i<n-1;i++)
            {
                if(s[i-1]=='1' && s[i+1]=='1')
                {
                    s[i]='0';
                }
            }
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')mini++;
            }
            cout<<mini<<" "<<maxi;


        }
        cout<<endl;
    }
}