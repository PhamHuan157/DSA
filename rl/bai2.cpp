#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left,*right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

void makeRoot(Node* root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void Insert(Node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        makeRoot(root,u,v,c);
    }
    Insert(root->left, u,v,c);
    Insert(root->right,u,v,c);
}

void InOrder(Node* root){
    if(root == NULL) return;
    InOrder(root->left);
    cout <<root->val<<" ";
    InOrder(root->right);
}

void PreOrder(Node* root){
    if(root == NULL) return;
    cout << root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root){
    if(root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout <<root->val<<" ";
}

int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        Node* temp = q.front(); 
        q.pop();
        cout <<temp->val<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

void SpiralOrder(Node* root){
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(st1.size() or st2.size()){
        while(st1.size()){
            Node* top = st1.top();
            st1.pop();
            cout <<top->val<<" ";
            if(top->right != NULL) st2.push(top->right);
            if(top->left != NULL) st2.push(top->left);
        }

        while(st2.size()){
            Node* top = st2.top(); 
            st2.pop();
            cout <<top->val<<" ";
            if(top->left != NULL) st1.push(top->left);
            if(top->right != NULL) st1.push(top->right);
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node* root = NULL;
        for(int i=0; i<n; i++){
            int u,v; char c; cin>>u>>v>>c;
            if(root == NULL){
                root = new Node(u);
                makeRoot(root,u,v,c);
            }else{
                Insert(root,u,v,c);
            }
        }
        cout <<"PreOrder: "; PreOrder(root);
        cout <<endl;
        cout <<"InOrder: "; InOrder(root);
        cout <<endl;
        cout <<"PostOrder: "; PostOrder(root);
        cout <<endl;
        cout <<"LevelOrder: "; levelOrder(root);
        cout <<endl;
        cout <<"SpiralOrder: "; SpiralOrder(root);
        cout <<endl;
    }
    
}