// xay cay nhi phan tim kiem

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left, *right;
    Node(int x){
        this->val = x;
        left = right = NULL;
    }
};
typedef Node* node;

// Node* makeNode(int data){
//     Node* moi = new Node();
//     moi->val = data;
//     moi->left = moi->right = NULL;
//     return moi;
// }

void Insert(node &root, int data){
    if(root == NULL){
        root = new Node(data);
    }else{
        if(data > root->val){
            Insert(root->right,data);
        }else Insert(root->left,data);
    }
}

void Display(Node* root){
    if(root == NULL) return;
    cout <<root->val<<" ";
    Display(root->left);
    Display(root->right);
}

int main(){
    Node* root = NULL;
    while(1){  
        cout <<"1. Chen\n";
        cout <<"2. Display\n";
        int n; cout<<"N: "; cin>>n;
        if(n== 1){
            int x; cout <<"Data: "; cin>>x;
            Insert(root,x);
        }else if(n == 2){
            Display(root);
            cout <<endl;
        }else break;

    }
}