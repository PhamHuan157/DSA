// cho thứ tự PreOrder của BST, đưa ra node trung gian (Node có ít nhất 1 con)
// Cách 1 cnp12

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right, *left;
};


Node* buildPre(int* a, int n){
    if(n<=0) return NULL;
    Node* root = new Node;
    root->val = a[0];
    int i = 0;
    for(i=1; i<n; i++){
        if(a[i] > a[0]){
            break;
        }
    }
    root->left = buildPre(&a[1],i-1);
    root->right = buildPre(&a[i], n-i);
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
        Node* root = buildPre(pre,n);
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