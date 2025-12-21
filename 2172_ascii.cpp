#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int g,c,l;
    cin>>g>>c>>l;
    int maxi=max({g,c,l});
    int mini=min({g,c,l});
    if(abs(maxi-mini)>=10)
    {
        cout<<"check again";
    }
    else 
    {
        if(g!=maxi && g!=mini)cout<<"final "<<g;
        else if(c!=maxi && c!=mini)cout<<"final "<<c;
        else cout<<"final "<<l;
    }

}