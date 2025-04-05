// perfect tree
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left,*right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

void makeRoot(Node* root,int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void Insert(Node* root, int u, int v, char c){
    if(root == NULL){
        return;
    }

    if(root->val == u){
        makeRoot(root,u,v,c);
    }
    Insert(root->left,u,v,c);
    Insert(root->right,u,v,c);
}

int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// 2 LA
bool CheckNode(Node* root){
    if(root == NULL) return true;
    if((root->left == NULL and root->right != NULL) or (root->right == NULL and root->left != NULL)) return false;
    return CheckNode(root->left) and CheckNode(root->right);
}

// 1 MUC
bool CheckLevel(Node* root, int level, int h){
    if(root == NULL) return true;
    if(root->left == NULL and root->right == NULL and level < h) return false;
    return CheckLevel(root->left, level +1,h) and CheckLevel(root->right, level+1,h);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node* root = NULL;
        for(int i=0; i<n; i++){
            int u,v; char c; 
            cin>>u>>v>>c;
            if(root == NULL){
                root = new Node(u);
                makeRoot(root,u,v,c);
            }else{
                Insert(root,u,v,c);
            }
        }
        int h = height(root);
        if(CheckLevel(root,1,h) and CheckNode(root)){
            cout <<"Perfect\n";
        }else cout <<"Not Perfect\n";
    }
}