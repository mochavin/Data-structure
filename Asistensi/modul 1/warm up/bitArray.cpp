#include <bits/stdc++.h>
#define loop(i,h) for(int i=0;i<h;i++)
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
    int satu = (1<<30) - 1;
    int nol = 0;
    int n; cin >> n;
    vector<int> v(n), a(n);
    loop(i,n) {cin >> v[i]; a[i] = v[i];}
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            string s; cin >> s;
            int x; cin >> x;
            if(s == "XOR") {
                satu ^= x;
                nol ^= x;
            }else if(s == "AND") {
                satu &= x;
                nol &= x;
            }else if(s == "OR") {
                satu |= x;
                nol |= x;
            }
        }else{
            loop(j, n){
                int temp = 0, t2 = a[j];
                loop(i, 30){
                    if((t2 >> i) & 1) {
                        temp ^= ((satu >> (i)) & 1) << i;
                    }else{
                        temp ^= ((nol >> (i)) & 1) << i;
                    }
                }
                v[j] = temp;
            }
            loop(i, n) cout << v[i] << " ";
            cout << endl;
        }
    }
}