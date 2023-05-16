#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxStage = 0;

struct AVLNode {
    int data;
    AVLNode *left, *right;
    int height, power, row, lvl;
};
vector<vector<pair<int,int>>> isiStage(105, vector<pair<int,int>> (105));
struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode* _avl_createNode(int value, int power) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->power = power;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b)? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int value, int power) {
        
        if(node==NULL)
            return _avl_createNode(value, power);
        if(value < node->data)
            node->left = _insert_AVL(node->left,value, power);
        else if(value > node->data)
            node->right = _insert_AVL(node->right,value, power);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if(balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if(balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode* _remove_AVL(AVLNode* node,int value){
        if(node==NULL)
            return node;
        if(value > node->data)
            node->right=_remove_AVL(node->right,value);
        else if(value < node->data)
            node->left=_remove_AVL(node->left,value);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->data=temp->data;
                node->right=_remove_AVL(node->right,temp->data);
            }    
        }

        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);

        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);

        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _traverse(AVLNode* root, int row, int lvl){
        if(!root) return;
        root->row = row;
        root->lvl = lvl;
        maxStage = max(maxStage, (lvl+row+2)/2);
        lvl++;
        _traverse(root->left, row-1, lvl);
        _traverse(root->right, row+1, lvl);
    }

    void _isiData(AVLNode* root) {
        if(!root) return;
        queue<AVLNode*> q;
        q.push(root);
        q.push(NULL); //penyangga tiap stage

        int stage = 0, urutan = 0;
        while(!q.empty()) {
            AVLNode *tmp = q.front();
            q.pop();
            if(tmp == NULL) {
                if(q.empty()) return;
                stage++;
                urutan = 0;
                q.push(NULL);
                continue;
            }
            while(tmp) {
                isiStage[stage][urutan] = {tmp->data, tmp->power};
                urutan++;
                if(tmp->right) q.push(tmp->right);
                tmp = tmp->left;
            }
        }

    }

public:
    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }

    void insert(int value, int power) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value, power);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }
    void traverse() {
        _traverse(_root, 0, 1);
    }

    void isiData() {
        _isiData(_root);
    }
};

int main()
{
    AVL set;
    set.init();
    string traveller, dungeon;
    int totalMonster, pwrTraveller;
    cin >> traveller >> totalMonster >> pwrTraveller >> dungeon;
    for(int i = 0; i < totalMonster; i++) {
        int pwrMonster, anuMonster;
        cin >> anuMonster >> pwrMonster;
        set.insert(anuMonster, pwrMonster);
    }
    set.traverse(); set.isiData();

    printf("*****************************************************************************\n");
    printf("The Abyss Game Dungeon %s (Diagonal Mode)\n", dungeon.c_str());
    printf("Traveller : %s\n", traveller.c_str());
    printf("Superpower : %d - Element Unite\n", pwrTraveller);
    printf("----------------------------------------------------------------------------\n");

    char ch;
    int idDongeoun = 1;
    for(int i = 0; i < 100; i++) {
        if(isiStage[i+1][0].first == 0) break;
        ch = 'A';
        printf("Stage %d:\n", idDongeoun);

        for(int j = 50; j >= 0; j--) {
            if(isiStage[i][j].first != 0) {
                printf("Monster %c%d_%d_%d: %d\n", ch, isiStage[i][j].first, idDongeoun, (int) (ch-'A'+1), isiStage[i][j].second);
                ch++;
            }
        }
        idDongeoun++;
        printf("\n");
    }
        // cout << "Final Stage:" << endl
    printf("Final Stage:\n");
    for(int i = 53; i >= 0; i--) {
        if(isiStage[maxStage-1][i].first) printf("Boss %s_%d: %d\n", dungeon.c_str(), isiStage[maxStage-1][i].first, isiStage[maxStage-1][i].second);
    }

    int tampung, damage;
    for(int i = 0; i < 100; i++) {
        tampung = 0;
        for(int j = 0; j < 55; j++) tampung += isiStage[i][j].second;
        if(pwrTraveller%2 == 0) damage = tampung*83/100;
        else damage = tampung*87/100;

        pwrTraveller -= damage;
        if(pwrTraveller < 0) {
            printf("\nHasil:\n");
            if(i == maxStage-1) printf("%s kalah dan mati di Dungeon %s pada Final Stage\n", traveller.c_str(), dungeon.c_str());
            else printf("%s kalah dan mati di Dungeon %s pada Stage %d\n", traveller.c_str(), dungeon.c_str(), i + 1);
            printf("*****************************************************************************");
            return 0;
        }
    }

    printf("\nHasil:\n");
    printf("%s menang melawan Dark Overlord dan memenangkan game di Dungeon %s\n", traveller.c_str(), dungeon.c_str());
    printf("*****************************************************************************");
    
    return 0;
}