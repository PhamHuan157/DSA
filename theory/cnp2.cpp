// Kiểm tra các lá của cây có cùng mức hay không
// Mức nên bắt đầu ở giá trị 1 (hoặc 0, chỉnh h-1);

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

void makeNode(Node* root, int u, int v, char c){
    if(c == 'L'){
        root->left = new Node(v);
    }else root->right = new Node(v);
}

void Insert(Node* root, int u, int v, char c){
    if(root == NULL){
        return;
    }
    if(root->val == u){
        makeNode(root,u,v,c);
    }
    Insert(root->left,u,v,c);
    Insert(root->right,u,v,c);
}

int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// level mức của lá, h là chiều cao cây
bool check(Node* root, int level, int h){
    if(root == NULL) return true;
    if(root->left == NULL and root->right == NULL and level < h){
        return false;
    }
    return check(root->left, level +1, h) and check(root->right, level +1, h);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node* root = NULL;
        while(n--){
            int u,v; cin>>u>>v;
            char c; cin>>c;
            if(root == NULL){
                root = new Node(u);
                makeNode(root,u,v,c);
            }else Insert(root,u,v,c);
        }
        int h = height(root);
        if(check(root, 1, h)){
            cout <<1<<endl;
        }else cout <<0<<endl;
    }

}

// 2 : t
// 2 : n
// 1 2 R 1 3 L
// => 1
// 4 : n
// 10 20 L 10 30 R 20 40 L 20 60 R
// => 0