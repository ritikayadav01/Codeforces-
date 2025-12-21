#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n>>a;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>a)count2++;
            if(arr[i]<a)count1++;
        }
        int b;
        if(count1>count2)b=a-1;
        else b=a+1;
        cout<<b<<endl;


    }
}