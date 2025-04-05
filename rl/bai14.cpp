// BST from preOrder

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right, *left;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

Node* makeTree(int pre[], int* idx, int l, int r, int n){
    if(l>r or *idx >= n) return NULL;
    Node* root = new Node(pre[*idx]);
    ++(*idx);
    if(l == r) return root;
    int ans;
    for(int i = l; i<=r; i++){
        if(pre[i] > root->val){
            ans = i;
            break;
        }
    }
    root->left = makeTree(pre,idx, *idx, ans-1, n);
    root->right = makeTree(pre,idx, ans, r, n);
    return root;
}

void makeRoot(Node* root, int u,int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
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
        Node* root = NULL;
        int pre[n];
        for(int i=0; i<n; i++){
            cin>>pre[i];
        }
        int idx = 0;
        root = makeTree(pre,&idx,0,n-1,n);
        postOrder(root);
        cout <<endl;
    }

}