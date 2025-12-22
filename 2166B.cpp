#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, n;
        cin>>a>>b>>n;
        if((long long)b*n<=a || b>=a)cout<<"1"<<endl;
        else cout<<"2"<<endl;
    }
}