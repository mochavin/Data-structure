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

bool mapContainsKey(std::map<string, vector<string>>& map, string key)
{
  if (map.find(key) == map.end()) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
  map<string, vector<string>> m;
  int n; cin >> n;
  while(n--){
    string s; cin >> s;
    if(s == "mkdir") {
      string p; cin >> p;
      if(p == "-p"){
        string s1; 
        getline(cin, s1);
        // cin.ignore();
        vector<string> tampung;
        stringstream ss(s1);
        string token;
        while (getline(ss, token, '/')) {
          if (!token.empty()) {
            tampung.push_back(token);
          }
        }
        string dir = tampung[0] + "/";
        loop1(i, tampung.size()-1){
          auto it =find(all(m[dir]), tampung[i]);
          if(it == m[dir].end()) {
            m[dir].push_back(tampung[i]);
          }
          dir += tampung[i] + "/";
        }
      }else{
        string s1;
        getline(cin, s1);
        cout << "command not found: " << s << " " << p << s1 << endl;
      }
    }else if(s == "ls") {
      string s1; 
      getline(cin, s1);
      // cin.ignore(); 
      if(mapContainsKey(m, s1) == false) {
        vector<string> tampung;
        stringstream ss(s1);
        string token;
        while (getline(ss, token, '/')) {
          if (!token.empty()) {
            tampung.push_back(token);
          }
        }
        string dir = tampung[0] + "/";
        loop(i, tampung.size()-1){
          auto it = find(all(m[dir]), tampung[i]);
          if(it == m[dir].end()) {
            cout << "ls: " << tampung[i] << ": No such file or directory" << endl;
            continue;
          }
          dir += tampung[i] + "/";
        }
        continue;
      }
      loop(i, m[s1].size()) {
        cout << m[s1][i] << " ";
      }
      cout << endl;
    }else{
      string s1; 
      getline(cin, s1);
      cout << "command not found: " << s << s1 << endl;
    }
  }
  // for(auto a : m) {
  //   cout << a.first << " ";
  //   loop(i, a.second.size()) {
  //     cout << a.second[i] << " ";
  //   }
  //   cout << endl;
  // }
}