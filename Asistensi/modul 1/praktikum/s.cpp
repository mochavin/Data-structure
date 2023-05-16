#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_front
#define loop(i,h) for(int i=0;i<h;i++)
#define loop1(i,h) for(ll i=1;i<=h;i++)
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 5;

void solve(){
    int n, sum = 0; cin >> n;
    vector<int> v(n);
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    loop(i, n) {
        int x; cin >> x;
        v[i] = x;
        sum += x;
    }
    if(sum % n != 0) {
        cout << -1 << endl; return;
    }
    int mean = sum / n;
    loop(i, n) {
        pq.push(v[i]);
        pq2.push(v[i]);
    }
    int ans = 0;
    while(!pq.empty() and !pq2.empty()) {
        if(pq.top() == mean and pq2.top() == mean) break;
        int x = pq.top(), y = pq2.top();
        pq.pop(); pq2.pop();
        int z = (x-y)/2;
        x -= z;
        y += z;
        pq.push(x); pq.push(y);
        pq2.push(x); pq2.push(y);
        ans++;
    }
   
    cout << ans;
    cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}