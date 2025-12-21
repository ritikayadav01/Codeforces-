#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long L = a[0], R = a[n - 1];
        long long best;

        if (L != -1 && R != -1) {
            best = abs(R - L);
        } 
        else if (L == -1 && R == -1) {
            best = 0;
            a[0] = a[n - 1] = 0;
        } 
        else if (L != -1 && R == -1) {
            best = 0;
            a[n - 1] = L;
        } 
        else { // L == -1 && R != -1
            best = 0;
            a[0] = R;
        }

        // fill all remaining -1 with 0 (lexicographically smallest)
        for (int i = 0; i < n; i++)
            if (a[i] == -1) a[i] = 0;

        cout << best << "\n";
        for (long long x : a) cout << x << " ";
        cout << "\n";
    }    
}