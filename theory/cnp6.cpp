// Cây nhị phân hoàn hảo (Mỗi node có 2 lá và các lá có cùng mức

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

// Check các cây có cùng 1 mức hay không
bool check1(Node* root, int level, int h){
    if(root == NULL) return true;
    if(root->left == NULL and root->right == NULL and level < h) return false;
    return (root->left, level+1,h) and (root->right, level+1,h);
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
        if(check1(root,1,h) and check2(root)){
            cout <<"YES\n";
        }else cout <<"NO\n";
    }

}

// 3 : t
// 6
// 10 20 L 10 30 R 20 40 L 20 50 R 30 60 L 30 70 R 
// => YES
// 2 
// 18 15 L 18 30 R
// => YES
// 5
// 1 2 L 2 4 R 1 3 R 3 5 L 3 6 R
// => NO
