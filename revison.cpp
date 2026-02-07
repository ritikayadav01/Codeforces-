#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int ans =0;
        if(arr[0]==-1 && arr[n-1]==-1)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i]==-1)arr[i]=0;
            }
            cout<<0<<endl;
            for(int i=0;i<n;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }
        else if(arr[0]==-1)
        {
            arr[0]=arr[n-1];
            for(int i=0;i<n;i++)
            {
                if(arr[i]==-1)arr[i]=0;
            }
            cout<<0<<endl;
            for(int i=0;i<n;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }
        else if(arr[n-1]==-1)
        {
            arr[n-1]=arr[0];
            for(int i=0;i<n;i++)
            {
                if(arr[i]==-1)arr[i]=0;
            }
            cout<<0<<endl;
            for(int i=0;i<n;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }
        else 
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i]==-1)arr[i]=0;
            }
            cout<<abs(arr[0]-arr[n-1])<<endl;
            for(int i=0;i<n;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }



    }
}