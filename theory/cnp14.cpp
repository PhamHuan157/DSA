// cho thứ tự PreOrder của BST, đưa ra node trung gian (Node có ít nhất 1 con)
// Cách 1 cnp12

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


// Xây BST bằng PreOrder
Node* build(int pre[], int *idx, int l, int r, int n){
    if(*idx >= n or l > r) return NULL;
    Node* root = new Node(pre[*idx]);
    ++(*idx);
    if(l == r) return root; // cây con chỉ có 1 phần tủ
    int ans; // chỉ số của phần tử bắt đầu từ cây con bên phải
    for(int i = l; i<=r; i++){
        if(pre[i] > root->val){
            ans = i;
            break;
        }
    }
    root->left = build(pre,idx, *idx, ans - 1, n);
    root->right = build(pre,idx, ans, r, n);
    return root;
}

int count(Node* root){
    if(root == NULL or root->left == NULL and root->right == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int pre[n];
        for(int i=0; i<n; i++){
            cin>>pre[i];
        }
        int idx = 0;
        Node* root = build(pre,&idx, 0,n-1,n);
        cout <<count(root)<<endl;
    }
}

// 2
// 6
// 10 5 1 7 40 50
// => 3
// 11 
// 30 20 15 25 23 28 40 35 33 38 45
// => 5