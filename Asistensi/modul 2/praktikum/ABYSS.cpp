#include<iostream>
#include <map>
#include <string>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define loop(i,h) for(int i=0;i<h;i++)
#define loop1(i,h) for(int i=1;i<=h;i++)
#define endl '\n'
using namespace std;
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;

map<int, int> monster;
int jero = 0, x;
string traveller, superpower, dungeon;
int n;

struct node {
    int val;
    node *left, *right;
    int power, kedalaman;
};

node* _insert(node *root, int x, int pow, int kedalaman) {
    if(root == NULL) {
        node *temp = new node;
        temp->val = x;
        temp->left = temp->right = NULL;
        temp->power = pow;
        temp->kedalaman = kedalaman;
        jero = max(jero, kedalaman);
        return temp;
    }
    if(x < root->val) {
        root->left = _insert(root->left, x, pow, ++kedalaman);
    }else{
        root->right = _insert(root->right, x, pow, ++kedalaman);
    }
    return root;
}
int it = 0;

void _find(node* root, int depth) {
    // cout << root->kedalaman << " ";
    if(root->kedalaman == depth) {
        cout << "Monster " << (char)('A'+it) << root->val << "_" << jero+1-depth << "_" << it+1 << ": " << root->power << endl;
        monster[jero+1-depth] += root->power;
        it++;
        // return;
    }
    if(root->left) _find(root->left, depth);
    if(root->right) _find(root->right, depth);
    // it = 0;
    return;
}

void _eval(node* root) {
    loop1(i, jero+1){
        if(x%2) {
            x -= 80*monster[i]/100;
        }else{
            x -= 90*monster[i]/100;
        }
        if(x < 0) {
            cout << traveller << " kalah dan mati di Dungeon " << dungeon << " pada " << (i == jero+1? "Final " : "") << "Stage";
            if(i != jero+1) cout << " " << i;
            return;
        }
    }
    cout << traveller << " menang melawan Dark Overlord dan memenangkan game di Dungeon " << dungeon;

}

void solve(){
    node *root = NULL;
    cin >> traveller >> n >> superpower >> x >> dungeon;
    loop(i, n) {
        int key, power; cin >> key >> power;
        root = _insert(root, key, power, 0);
    }
    monster[jero+1] += root->power;
    cout << "*****************************************************************************" << endl;
    cout << "The Abyss Game Dungeon " << dungeon << endl << endl;
    cout << "Traveller : " << traveller << endl;
    cout << "Superpower : " << superpower << " - " << x << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    
    loop(i, jero) {
        cout << "Stage " << i+1 << ":" << endl;
        _find(root, jero-i);
        cout << endl;
        it = 0;
    }
    cout << "Final Stage:" << endl;
    cout << "Dark Overlord " << dungeon << "_" << root->val << ": " << root->power << endl;
    cout << endl << "Result:" << endl;
    _eval(root);
    cout << endl << "*****************************************************************************";

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