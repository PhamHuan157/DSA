// node trung gian

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left,*right;
    Node(int x){
        val = x;
        right = left = NULL;
    }
};

Node* makeTree(int pre[], int* idx, int l, int r, int n){
    if(l > r or *idx >= n) return NULL;
    Node* root = new Node(pre[*idx]);
    ++(*idx);
    if(l == r) return root;
    int ans;
    for(int i=l; i<=r; i++){
        if(pre[i] > root->val){
            ans = i;
            break;
        }
    }

    root->left = makeTree(pre,idx,*idx,ans-1,n);
    root->right = makeTree(pre,idx,ans,r,n);
    return root;
}

int count(Node* root){
    if(root == NULL or root->left == NULL or root->right == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node* root = NULL;
        int pre[n];
        for(int i=0; i<n; i++) cin>>pre[i];
        int idx = 0;
        root = makeTree(pre,&idx,0,n-1,n);
        cout <<count(root)<<endl;
    }
}