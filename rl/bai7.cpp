// cnp day du

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left, *right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

void makeRoot(Node* root, int u,int v, char c){
    if(c =='L') root->left = new Node(v);
    else root->right = new Node(v);
}

void Insert(Node* root, int u, int v, int c){
    if(root == NULL){
        return;
    }
    if(root->val == u){
        makeRoot(root,u,v,c);
    }
    Insert(root->left, u,v,c);
    Insert(root->right,u,v,c);
}

bool checkFull(Node* root){
    if(root == NULL) return true;
    if((root->left == NULL and root->right != NULL) or (root->left != NULL and root->right == NULL)) return false;
    return checkFull(root->left) and checkFull(root->right);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node* root =NULL;
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
        if(checkFull(root)){
            cout <<"YES\n";
        }else cout <<"NO\n";
    }
}