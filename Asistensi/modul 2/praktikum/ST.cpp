#include <iostream>
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
};

node* _insert(node *root, ll x) {
    if(root == NULL) {
        node *temp = new node;
        temp->val = x;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(x < root->val) {
        root->left = _insert(root->left, x);
    }else{
        root->right = _insert(root->right, x);
    }
    return root;
}
ll _findMax(node *root){
    if(root->right == NULL) {
        return root->val;
    }
    return _findMax(root->right);
}
ll _findMin(node *root) {
    if(root->left == NULL) {
        return root->val;
    }
    return _findMin(root->left);
}

void solve(){
    ll q; cin >> q;
    node *root = NULL;
    loop(i, q) {
        int x; cin >> x;
        root = _insert(root, x);
    }
    cout << _findMax(root) << " " << _findMin(root) << endl;
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