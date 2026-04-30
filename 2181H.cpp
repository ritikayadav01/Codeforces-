#include <bits/stdc++.h>

using namespace std;
 
int main(){
	int w, h, d, n;
	cin>>w>>h>>d>>n;
	int x = gcd(n, w);
	int y = gcd(n/x, h);
	int z = gcd(n/(x*y), d);
	if(x*y*z==n){
		cout<<x-1<<" "<<y-1<<" "<<z-1;
	} else{
		cout<<-1;
	}
}