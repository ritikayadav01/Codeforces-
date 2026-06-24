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
        vector<int>h(n);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>h[i];
            if(h[i]>maxi)maxi=h[i];
            if(h[i]<mini)mini=h[i];
        }
        cout<<maxi+1-mini<<endl;
    }
}