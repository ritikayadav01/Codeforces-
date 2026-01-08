#include<bits/stdc++.h>
using namespace std;
int _t_,n,a[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[1]+a[n]==0)
        cout<<"Bob\n";
    else
        cout<<"Alice\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}