// cnp bang nhau

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

void makeRoot(Node* root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void Insert(Node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u) makeRoot(root, u,v,c);
    Insert(root->left,u,v,c);
    Insert(root->right,u,v,c);
}

bool check(Node* root1, Node* root2){
    if(root1 == NULL and root2 == NULL) return true;
    if(root1 != NULL and root2 != NULL){
        return (root1->val == root2->val) and check(root1->left, root2->left) and check(root1->right, root2->right); 
    }
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node* root1 = NULL;
        for(int i=0; i<n; i++){
            int u,v;char c; cin>>u>>v>>c;
            if(root1 == NULL){
                root1 = new Node(u);
                makeRoot(root1,u,v,c);
            }else Insert(root1,u,v,c);
        }
        int m; cin>>m;
        Node* root2 = NULL;
        for(int i=0; i<m; i++){
            int u,v; char c;
            cin>>u>>v>>c;
            if(root2 == NULL){
                root2 = new Node(u);
                makeRoot(root2,u,v,c);
            }else Insert(root2,u,v,c);
        }
        if(check(root1,root2)){
            cout <<"YES\n";
        }else cout <<"NO\n";
    }

}