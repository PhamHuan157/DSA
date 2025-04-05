// tong node la ben phai

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right, *left;
    Node(int x){
        val = x;
        right = left = NULL;
    }
};

void makeRoot(Node* root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right =  new Node(v);
}

void Insert(Node* root, int u,int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        makeRoot(root, u,v,c);
        return;
    }
    Insert(root->left, u,v,c);
    Insert(root->right,u,v,c);
}

int rightSum(Node* root){
    if (root == NULL) return 0;
    int sum = 0;
    if (root->right) {
        sum += root->right->val;
        // + rightSum(root->right);
    }
    sum += rightSum(root->left);
    sum += rightSum(root->right);

    return sum;
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
            }else Insert(root,u,v,c);
        }
        cout <<rightSum(root)<<endl;
    }
}