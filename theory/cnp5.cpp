// Duyệt theo mức (levelOrder - giống bfs)
// Duyệt xoắn ốc (spiralOrder

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

// Duyệt theo mức
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        Node* top = q.front(); q.pop();
        cout <<top->val<<" ";
        // Kiểm tra xem các node trái - phải khác nullptr hay không
        if(top->left != NULL) q.push(top->left);
        if(top->right != NULL) q.push(top->right);
    }
}

// Duyệt xoắn ốc
void SpiralOrder(Node* root){
    stack<Node*> s1, s2;
    s1.push(root);
    while(s1.size() or s2.size()){
        while(s1.size()){
            Node* tmp = s1.top(); s1.pop();
            cout << tmp->val<<" ";
            // Đẩy các Node của s1 từ phải sang trái
            if(tmp->right != NULL) s2.push(tmp->right);
            if(tmp->left != NULL) s2.push(tmp->left);
        }

        while(s2.size()){
            Node* tmp = s2.top(); s2.pop();
            cout << tmp->val<<" ";
            // Đẩy các Node của s1 từ trái sang phải
            if(tmp->left != NULL) s1.push(tmp->left);
            if(tmp->right != NULL) s1.push(tmp->right);
        }
    }
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
        levelOrder(root);
        cout <<endl;
        SpiralOrder(root);
        cout <<endl;
    }

}

// levelOrder
// 2
// 2
// 1 2 R 1 3 L
// => 1 3 2
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R
// 10 20 30 40 60
// --------------------------------
// SpiralOrder
// 2
// 2
// 1 2 R 1 3 L
// 1 3 2 
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R
// 10 20 30 60 40 