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
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        stack<int>st;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && arr[st.top()]>arr[i])
            {
                ans++;
                // st.pop();
            }
            else st.push(i);
        }
        cout<<ans<<endl;
    }
}