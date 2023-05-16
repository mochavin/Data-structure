#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define loop(i,h) for(int i=0;i<h;i++)
#define loop1(i,h) for(ll i=1;i<=h;i++)
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
    int n, p, w; cin >> n >> p >> w;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    sort(rall(v));
    loop(i, p){
        v[i] -= min(v[i], w);
    }
    // loop(i, n) cout << v[i] << " ";
    int sum = accumulate(all(v), 0);
    printf("%.2lf", (double) sum/60);
}