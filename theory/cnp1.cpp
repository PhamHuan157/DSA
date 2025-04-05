// Cách xây cây

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    //Hai con trỏ left và right
    Node* left, *right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

// Tạo gốc cho cây
// cha là u, con là v, c là trái - phải
void makeNode(Node* root, int u, int v, char c){
    if(c == 'L'){
        root->left = new Node(v);
    }else root->right = new Node(v);
}

// Hàm thêm 1 node cho cây
void Insert(Node* root, int u, int v, char c){
    // makeRoot chỗ này sẽ bị segmentation fault vì root == NULL, không thể makeNode
    if(root == NULL){
        return;
    }
    // Nếu không kiểm tra root->val == u hay không thì sẽ bị lỗi segmentation fault khi makeNode ở trên
    if(root->val == u){
        makeNode(root,u,v,c);
    }
    // Tìm sang trái
    Insert(root->left,u,v,c);
    // Tìm sang phải
    Insert(root->right,u,v,c);
}

int main(){
    // số lượng test case
    int t; cin>>t;
    while(t--){
        // số lượng cạnh
        int n; cin>>n;
        Node* root = NULL;
        while(n--){
            // các đỉnh,..
            int u,v; cin>>u>>v;
            char c; cin>>c;
            if(root == NULL){
                // Tạo node mới (root mới)
                root = new Node(u);
                makeNode(root,u,v,c);
            }else Insert(root,u,v,c);
        }
    }

}