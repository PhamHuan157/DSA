// preOrder AVL

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right, *left;
    Node(int x){
        val = x;
        right = left = NULL;
    }
};


Node* makeTree(int pre[], int l, int r){
    if(l > r) return NULL;
    int m = (l+r)/2;
    Node* root = new Node(pre[m]);
    root->left = makeTree(pre,l,m-1);
    root->right = makeTree(pre,m+1,r);
    return root;
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout <<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout <<root->val<<" ";    
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int pre[n];
        Node* root = NULL;
        for(int i=0; i<n; i++) cin>>pre[i];
        sort(pre,pre+n);
        root = makeTree(pre,0,n-1);
        preOrder(root);
        cout <<endl;
        postOrder(root);
        cout <<endl;
    }
}