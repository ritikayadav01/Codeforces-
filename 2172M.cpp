#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> product(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> product[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS from port city 1
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Answer for each product type
    vector<int> ans(k + 1, 0);
    for (int i = 1; i <= n; i++) {
        int p = product[i];
        ans[p] = max(ans[p], dist[i]);
    }

    // Output
    for (int p = 1; p <= k; p++) {
        cout << ans[p] << " ";
    }
    cout << "\n";

    return 0;
}
