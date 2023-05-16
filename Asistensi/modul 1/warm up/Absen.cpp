#include <bits/stdc++.h>
#define loop(i,h) for(int i=0;i<h;i++)
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    loop(i, n) {
        int x; cin >> x;
        ans += x;
        
    }
    cout << ans << " " << n-ans ;
}