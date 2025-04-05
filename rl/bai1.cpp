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

void Branch(Node* root,int u,int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void Insert(Node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        Branch(root, u,v,c);
    }
    Insert(root->left, u,v,c);
    Insert(root->right,u,v,c);
}


int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool Check(Node* root, int level, int h){
    if(root == NULL) return true;
    else if(root->left == NULL and root->right == NULL and level < h){
        return false;
    }
    return Check(root->left, level +1,h) and Check(root->right, level+1, h); 
}


int main(){
    int t; cin>>t;
    while(t--){
        Node* root = NULL;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int u,v; char c;
            cin>>u>>v>>c;
            if(root == NULL){
                root = new Node(u);
                Branch(root,u,v,c);
            }else{
                Insert(root,u,v,c);
            }
        }
        int h = height(root);
        if(Check(root,1,h)){
            cout <<"Yes\n";
        }else cout <<"No\n";
        
    }
}