#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int flag=-1;
        for(int i=0; i<n-1; i++){
            if(abs(a[i]-a[i+1])<=1){
                flag=0;
                break;
            }
        }
        if(!flag){
            cout<<0<<endl;
            continue;
        }
        for(int i=1; i<n-1; i++){
            if(a[i]>a[i-1] and a[i]>a[i+1]){
                flag=1;
                break;
            }
            if(a[i]<a[i-1] and a[i]<a[i+1]){
                flag=1;
                break;
            }
        }
        cout<<flag<<endl;
    }
}