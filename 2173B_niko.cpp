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
        
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long l= 0, h = 0;

    for (int i = 0; i < n; i++) {
        long long A = a[i], B = b[i];

        long long r1 = l - A;
        long long r2 = h - A;
        long long c1 = B - h;
        long long c2 = B - l;

        l = min(r1, c1);
        h = max(r2, c2);
    }

    cout << h << endl;

    }
}