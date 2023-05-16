#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

bool vis[6005];

struct node {
    int value;
    node *left, *right, *parent;
    int keParent;
};

node* _insert(node* root, int val, int keParent, node *parent) {
    if(root == NULL) {
        node* tmp = new node;
        tmp->value = val;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->keParent = keParent;
        tmp->parent = parent;
        return tmp;
    }
    parent = root;
    if(root->value > val) root->left = _insert(root->left, val, keParent, parent);
    else root->right = _insert(root->right, val, keParent, parent);
    return root;
}

node* _find(node* root, int n) {
    if(root->value == n) {
        return root;
    }
    if(root->left && root->value > n) root = _find(root->left, n);
    else if(root->right && root->value < n) root = _find(root->right, n);
    return root;
}

int _eval(node* root, int jarak) {
    if(root->left == NULL && root->right == NULL) {
        return jarak;
    }else{
        vector<int> sementara;
        vis[root->value] = true;
        sementara.push_back(root->value);
        node* tmp = root;
        int mins = 1e9;
        if(root->left && vis[root->left->value] == false) mins = min(mins, _eval(root->left, jarak+root->left->keParent));
        if(root->right && vis[root->right->value] == false) mins = min(mins, _eval(root->right, jarak+root->right->keParent));
        if(root->parent && vis[root->parent->value] == false)  mins = min(mins, _eval(root->parent, jarak + root->keParent));
        for(int i = 0; i < sementara.size(); i++) {
            vis[sementara[i]] = false;
        }
        sementara.clear();
        return mins;
    }
}

int main() {
    node* root = NULL;
    int n, t; cin >> n >> t;
    root = _insert(root, t, 0, NULL);
    for(int i = 0; i < n; i++) {
        int nilai, keParent; cin >> nilai >> keParent;
        root = _insert(root, nilai, keParent, NULL);
    }
    int it; cin >> it;
    while(it--) {
        int p; cin >> p;
        node* tmp = root;
        tmp = _find(tmp, p); 
        int ans = _eval(tmp, 0);
        cout << ans << endl;
    }
    return 0;
    
}