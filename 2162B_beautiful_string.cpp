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
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                ans.push_back(i+1);
            }
        }
        cout<<(int)ans.size()<<endl;
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;

    }

}