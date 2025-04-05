// Cây AVL, đưa ra thứ tự postOrder (Nhớ sort mảng trước)
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
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a,a+n);
        Node* root = build(a,0,n-1);
        postOrder(root);
        cout<<endl;
    }
}

// 2
// 11
// 40 28 45 38 33 15 25 20 23 35 30
// => 20 15 28 25 23 35 33 45 40 38 30 
// 10
// 1 2 3 4 5 6 7 8 9 10
// => 1 4 3 2 7 6 10 9 8 5