// Cây nhị phân bằng nhau (là 2 cây giống nhau)

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

bool Identical(Node* root1, Node* root2){
    if(root1 == NULL and root2 == NULL) return true;
    if(root1 != NULL and root2 != NULL){
        return (root1->val == root2->val) and (Identical(root1->left, root2->left)) and (Identical(root1->right, root2->right)); 
    }
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node* root1 = NULL;
        while(n--){
            int u,v; cin>>u>>v;
            char c; cin>>c;
            if(root1 == NULL){
                root1 = new Node(u);
                makeNode(root1,u,v,c);
            }else Insert(root1,u,v,c);
        }

        cin>>n;
        Node* root2 = NULL;
        while(n--){
            int u,v; cin>>u>>v;
            char c; cin>>c;
            if(root2 == NULL){
                root2 = new Node(u);
                makeNode(root2,u,v,c);
            }else Insert(root2,u,v,c);
        }
        if(Identical(root1,root2)){
            cout <<"YES\n";
        }else cout <<"NO\n";
    }

}

// 2  : t
// 2 
// 1 2 L 1 3 R 
// 2
// 1 2 L 1 3 R
// => YES
// 2
// 1 2 L 1 3 R
// 2
// 1 3 L 1 2 R
// => NO