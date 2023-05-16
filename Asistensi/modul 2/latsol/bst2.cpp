#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define loop(i,h) for(ll i=0;i<h;i++)
#define loop1(i,h) for(ll i=1;i<=h;i++)
#define endl '\n'
using namespace std;
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;

void solve(){
    ll q; cin >> q;
    priority_queue<ll> pq;
    priority_queue<ll, vector<ll>, greater<ll>> pq1;
    jump : 
    while(q--) {
        ll query, x; cin >> query >> x;
        if(query == 1) {
            // insert
            pq.push(x); pq1.push(x);
        }else{
            // find
            if(abs(pq.top() - x) <= abs(pq1.top() - x)) {
                priority_queue<ll> temp = pq;
                int it = 1;
                while(!temp.empty()) {
                    if(temp.top() == x) {
                        cout << it << endl;
                        goto jump;
                    }
                    it++;
                    temp.pop();
                }
                cout << "Data tidak ada" << endl;
            }else{
                priority_queue<ll, vector<ll>, greater<ll>> temp = pq1;
                int it = 1;
                while(!temp.empty()) {
                    if(temp.top() == x) {
                        cout << pq.size()-it+1 << endl;
                        goto jump;
                    }
                    it++;
                    temp.pop();
                }
                cout << "Data tidak ada" << endl;
            }
        }
    }
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}