#include <bits/stdc++.h>
using namespace std;
 void solve(){
	int n;
	cin >> n;
	if (n % 2 == 0){
		for (int i = 0; i < n; i += 2){
			cout << (i + 2) << ' ' << (i + 1) << ' ' << (i + 1) << ' ' << (i + 2) << ' ';
			cout << (i + 1) << ' ' << (i + 2) << ' ' << (i + 2) << ' ' << (i + 1) << ' ';
		}
	}
	else{
		cout << "3 3 2 1 1 2 1 2 2 3 1 3 ";
		for (int i = 3; i < n; i += 2){
			cout << (i + 2) << ' ' << (i + 1) << ' ' << (i + 1) << ' ' << (i + 2) << ' ';
			cout << (i + 1) << ' ' << (i + 2) << ' ' << (i + 2) << ' ' << (i + 1) << ' ';
		}
	}
	cout << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
