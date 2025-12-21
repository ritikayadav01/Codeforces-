#include<iostream>
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
     int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end(),greater<int>());
   
    vector<int>voucher(k);
    for(int i=0;i<k;i++)
    {
        cin>>voucher[i];
    }
    sort(voucher.begin(),voucher.end(),greater<int>());
    long long totalcost = 0;
    for (int x : arr) totalcost += x;
    int currrentindex = 0;
    sort(voucher.begin(), voucher.end());
    for (int i = 0; i < k; ++i) {
        int gs = voucher[i];
        if (currrentindex + gs - 1 >= n) break;
        totalcost -= arr[currrentindex + gs - 1];
        currrentindex += gs;
    }
    cout << totalcost << "\n";
   }

   return 0;
}