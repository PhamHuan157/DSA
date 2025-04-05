// Duyệt cây Binary Search Tree (BST)
// Đặc điểm BST: node con bên trái nhỏ hơn node gốc và node gốc nhỏ hơn node con bên phải
// Và các cây con bên trái và cây con bên phải cũng phải tuân theo đặc điểm trên
// Cho cây theo thứ tụ PreOrder đưa ra thứ tự sau của cây BST
// Cách xây cây BST khác (cnp14 fix error trước)
// BST khác với AVL, không cần sort trước, AVL(Cây cân bằng) thì phải sort trước

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

// Index là chỉ số để lưu lại chỉ số gốc cây trong mảng preOrder 
// chỉ số gốc cây ko bao giờ cũng là phần tử ban đầu nên phải thay đổi chỉ số
// sau mỗi lần gọi đệ quy
// l,r cận trái phải, n số lượng phần tử
Node* build(int pre[], int *idx, int l, int r, int n){
    if(*idx >= n or l > r) return NULL; // base case
    Node* root = new Node(pre[*idx]);
    (*idx)++;
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
        for(int i=0; i<n; i++){
            cin>>pre[i];
        }
        int index = 0;
        Node* root = build(pre, &index,0,n-1,n);
        postOrder(root);
    }

}


// 2
// 5
// 40 30 35 80 100
// => 35 30 100 80 40  
// 8
// 40 30 32 35 80 90 100 120
// => 35 32 30 120 100 90 80 40 