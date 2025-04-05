// cây AVL: cây nhị phân tìm kiếm cân bằng
// Đưa ra node gốc (Node giữa)

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

Node* build(int a[], int l, int r){
    if(l>r) return NULL;
    int m = (l+r)/2;
    Node* root = new Node(a[m]);
    root->left = build(a, l, m-1);
    root->right = build(a,m+1,r);
    return root;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        Node* root = build(a,0,n-1);
        cout <<root->val<<endl;
    }
}


// 2
// 11
// 40 28 45 38 33 15 25 20 23 35 30
// => 30
// 10
// 1 2 3 4 5 6 7 8 9 10
// => 5