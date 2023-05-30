#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i,h) for(int i=0;i<h;i++)
#define loop1(i,h) for(int i=1;i<=h;i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353

using namespace std;

ll M = 1e9 + 7;
const ll N = 1e4 + 5;
const ll vertex = 1e6 + 5;
ll MM = 1e18;

int a, b;
vector<vector<int>> adj(200);
vector<int> color(200, 0);


bool isSafe(int it) {
    loop(i, a) {
        for(auto j : adj[i]) {
            if(color[i] == color[j]) return false;
        }
    }
    return true;    
}

int cek(int it) {
    if(it == a) {
        if(isSafe(it)) {
            cout << "YES!" << endl;
            return 1;
        }
        return 0;
    }
    loop1(i, b) {
        color[it] = i;
        if(cek(it+1)) return 1;
        color[it] = 0;
    }
    return 0;
}

void solve() {
    cin >> a >> b;
    cin.ignore();
    
    loop(_, a) {
        string s;
        getline(cin, s);
        vector<int> temp;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == ' ' || s[i] == ',' || s[i] == '-' || s[i] == '>') continue;
            temp.pb(s[i]-'A');
        }
        adj[(int) (s[0]-'A')] = temp;
    }
    
    if(!cek(0)) cout << "NO!" << endl;
}

int main() {
    solve();
    return 0;
}
