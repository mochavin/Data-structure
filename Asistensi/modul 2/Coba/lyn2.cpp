#include<iostream>
#include<map>
#include<vector>
using namespace std;

int maxKedalaman = 0;
map<int, vector<int>> isiKedalaman;

struct node {
    int value;
    node *left, *right;
    int kedalaman;
};

node* _insert(node* root, int val, int kedalaman) {
    if(root == NULL) {
        node* tmp = new node;
        tmp->value = val;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->kedalaman = kedalaman;
        isiKedalaman[kedalaman].push_back(val);
        maxKedalaman = max(kedalaman, maxKedalaman);
        return tmp;
    }   
    kedalaman++;
    if(root->value > val) root->left = _insert(root->left, val, kedalaman);
    else root->right = _insert(root->right, val, kedalaman);
    return root;
}

int main() {
    node* root = NULL;
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int nilai; cin >> nilai;
        root = _insert(root, nilai, 0);
    }
    int toggle = 0;
    for(int i = maxKedalaman; i >= 0; i--) {
        if(toggle == 0) {
            int ujung = INT_MAX;
            for(int j = 0; j < isiKedalaman[i].size(); j++) {
                ujung = min(ujung, isiKedalaman[i][j]);
            }
            cout << ujung;
        }else{
            int ujung = 0;
            for(int j = 0; j < isiKedalaman[i].size(); j++){
                ujung = max(ujung, isiKedalaman[i][j]);
            }
            cout << ujung;
        }
        cout << " ";
        toggle ^= 1;
    }
    return 0;
    
}