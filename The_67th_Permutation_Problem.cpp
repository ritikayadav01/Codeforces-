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
        int k=3*n;
        for(int i=1;i<=n;i++)
        {
            cout<<i<<" "<<k-1<<" "<<k<<" ";
            k-=2;
        }
        cout<<endl;
    }
}