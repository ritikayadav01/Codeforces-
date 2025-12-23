#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int smallest = arr[0];
        int secondSmallest = arr[1];
        int limit = 2 * smallest;
        int maxAllowed = smallest;
        auto it = upper_bound(arr.begin(), arr.end(), limit);
        if (it != arr.begin()) {
            maxAllowed = *(it - 1);
        }
        int answer = smallest;

        if (secondSmallest > limit) {

            int candidate = secondSmallest - smallest;

            while (candidate > smallest) {
                if (candidate > maxAllowed &&
                    !binary_search(arr.begin(), arr.end(), candidate)) {

                    answer = candidate;
                    break;
                }
                candidate--;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
