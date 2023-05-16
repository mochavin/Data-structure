#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>

struct comp{
    bool operator()(pii a, pii b) {
        return a.first < b.first;
    }
};


void showpq(priority_queue<pii, vector<pii>, comp> gq) 
{ 
    priority_queue<pii, vector<pii>, comp> g = gq; 
    while (!g.empty()) { 
        cout << g.top().first << ' ' << g.top().second << '\n'; 
        g.pop(); 
    } 
    cout << '\n'; 
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
    priority_queue<pii, vector<pii>, comp> pq;
    int q; cin >> q;    
    while(q--) {
        string s; cin >> s;
        if(s == "MASUK") {
            int id, prior; cin >> id >> prior;
            pq.push({prior, id});
        }else{
            if(pq.empty()) {
                cout << "HORE" << endl;
                continue;
            }
            cout << pq.top().second << endl;
            pq.pop();
        }
    }
    // showpq(pq);
}