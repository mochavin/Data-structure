
#include <bits/stdc++.h>
#include <iostream> 

using namespace std;

int main()
{
    stack<string> st;
    int ans = 0;
    int n; 
    cin >> n;
    cin.ignore();
    while(n--) {
        string s;
        getline(cin, s);
        st.push(s);
        if(s[0] == 'C') ans++;
    }
    int q; 
    cin >> q;
    cin.ignore();
    while(q--) {
        string s; 
        getline(cin, s);
        if(s[0] == 'O') {
            if(st.top()[0] == 'C'){
                ans--;
                cout << "I'm going crazy, right?" << endl;
                st.pop();
            }
        }else{
            if(ans >= 5) {
                cout << "He's the one that's living in my system" << endl;
            }else{
                cout << "They keep on asking me, \"Who is he?\"" << endl;
            }
        }
    }
    return 0;
}