#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, a);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*node+1, l, mid, a);
        build(2*node+2, mid+1, r, a);
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return LLONG_MAX;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return min(
            query(2*node+1, l, mid, ql, qr),
            query(2*node+2, mid+1, r, ql, qr)
        );
    }

    int range_min(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    if(k==1)
    {
        cout<<*min_element(arr.begin(),arr.end())<<endl;
        return 0;
    }
    if(k>=3)
    {
        cout<<*max_element(arr.begin(),arr.end())<<endl;
        return 0;
    }

    SegTree st(arr);
    int ans =LLONG_MIN;
     for (int i = 0; i < n - 1; i++) {
        int leftMin = st.range_min(0, i);
        int rightMin = st.range_min(i + 1, n - 1);
        ans = max(ans, max(leftMin, rightMin));
    }
    cout<<ans<<endl;
    
}