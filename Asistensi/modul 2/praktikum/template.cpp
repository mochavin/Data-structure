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
struct node {
    ll val;
    node *left, *right;
    ll size;
};

ll getSize(node* root) {
    return root ? root->size : 0;
}

void updateSize(node* root) {
    root->size = getSize(root->left) + getSize(root->right) + 1;
}

node* _insert(node *root, ll x) {
    if(root == NULL) {
        node *temp = new node;
        temp->val = x;
        temp->left = temp->right = NULL;
        temp->size = 1;
        return temp;
    }
    if(x < root->val) {
        root->left = _insert(root->left, x);
    }else{
        root->right = _insert(root->right, x);
    }
    updateSize(root);
    return root;
}

ll _find(node *root, ll x) {
    if(root == NULL) return -M;
    if(root->val == x) return getSize(root->right)+1;
    if(x < root->val) return _find(root->left, x) + getSize(root->right) + 1;
    return _find(root->right, x);
}


void solve(){
    ll q; cin >> q;
    node *root = NULL;
    while(q--) {
        ll query, x; cin >> query >> x;
        if(query == 1) {
            // insert
            root = _insert(root, x);
        }else{
            // find
            ll ans = _find(root, x);
            if(ans < 0) cout << "Data tidak ada" << endl;
            else cout << ans << endl;
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