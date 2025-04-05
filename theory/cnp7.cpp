// Cây nhị phân đầy đủ (Nếu tất cả các node trung gian của nó đều có 2 con => full binary tree)

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

// Check các node có đủ 2 lá không
bool check2(Node* root){
    if(root == NULL) return true;
    if((root->left == NULL and root->right != NULL) or (root->left!= NULL and root->right == NULL)){
        return false;
    }
    return check2(root->left) and check2(root->right); 
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
        if(check2(root)){
            cout <<"YES\n";
        }else cout <<"NO\n";
    }

}


// 2 : t
// 4
// 1 2 L 1 3 R 2 4 L 2 5 R
// => YES
// 3
// 1 2 L 1 3 R 2 4 L
// => NO