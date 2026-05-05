#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>arr(7);
        for(int i=0;i<7;i++)cin>>arr[i];
        sort(arr.begin(),arr.end());
        int sum=0;
        for(int i=0;i<6;i++)sum+=-arr[i];
        sum+=arr[6];
        cout<<sum<<endl;
    }
}