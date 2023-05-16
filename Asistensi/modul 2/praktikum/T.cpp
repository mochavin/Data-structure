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
int uang; 
map<int,bool> pernah;

struct node {
    ll val;
    node *left, *right, *parent;
    ll size;
    ll harga;
    ll minim = M;
};

ll getSize(node* root) {
    return root ? root->size : 0;
}

void updateSize(node* root) {
    root->size = getSize(root->left) + getSize(root->right) + 1;
}

node* _insert(node *root, ll x, ll harga, node* parent) {
    if(root == NULL) {
        node *temp = new node;
        temp->val = x;
        temp->left = temp->right = NULL;
        temp->size = 1;
        temp->harga = harga;
        temp->parent = parent;
        return temp;
    }
    if(x < root->val) {
        root->left = _insert(root->left, x, harga, root);
    }else{
        root->right = _insert(root->right, x, harga, root);
    }
    updateSize(root);
    return root;
}

node* _find(node *root, ll x) {
    if(root->val == x) return root;
    if(x < root->val) return _find(root->left, x);
    return _find(root->right, x);
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

bool traverse(node* root, int sisa) {
    if(sisa < 0) return false;
    if(!root->left and !root->right) return true;
    pernah[root->val] = true;
    bool f = false;
    node *temp = root;
    if(root->parent and pernah[root->parent->val] == false) f |= traverse(root->parent, sisa-root->harga);
    pernah.clear();
    if(f) return f;
    root = temp;
    pernah[root->val] = true;
    if(root->left and pernah[root->left->val] == false) f |= traverse(root->left, sisa-root->left->harga);
    pernah.clear();
    if(f) return f;
    root = temp;
    pernah[root->val] = true;
    if(root->right and pernah[root->right->val] == false) f |= traverse(root->right, sisa-root->right->harga);
    pernah.clear();
    root = temp;
    return f;
}

bool cariCuy(node* root, int x) {
    root = _find(root, x);
    bool ans = traverse(root, uang);
    return ans;
}

void solve(){
    node *root = NULL;
    node *roo = root;
    cin >> uang;
    int n, r; cin >> n >> r;
    root = _insert(root, r, 0, NULL);
    n--;
    while(n--){
        ll a, h; cin >> a >> h;
        root = _insert(root, a, h, root);
    }
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        // cout << cariCuy(root, x) << " ";
        if(cariCuy(root, x)) cout << "yey, bisa refreshing :)" << endl; 
        else cout << "bruhh -_-" << endl;
        
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