// Cây AVL, đưa ra thứ tự preOrder (Nhớ sort mảng trước)
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left, *right;
    Node(int x){
        val = x;
        right = left = NULL;
    }
};

Node* build(int a[], int l, int r){
    if(l>r) return NULL;
    int m = (l+r)/2;
    Node* root = new Node(a[m]);
    root->left = build(a,l,m-1);
    root->right = build(a,m+1,r);
    return root;
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout <<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a,a+n);
        Node* root = build(a,0,n-1);
        preOrder(root);
        cout<<endl;
    }
}

// 2
// 11
// 40 28 45 38 33 15 25 20 23 35 30
// => 30 23 15 20 25 28 38 33 35 40 45 
// 10
// 1 2 3 4 5 6 7 8 9 10
// => 5 2 1 3 4 8 6 7 9 10