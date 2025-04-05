// Tổng lớn nhất

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

int maxSum(Node* root, int& ans){
    if(root == NULL) return 0;
    if(root->left == NULL and root->right == NULL){
        return root->val;
    }

    int l = maxSum(root->left, ans);
    int r = maxSum(root->right, ans);

    if(root->left != NULL and root->right != NULL){
        ans = max(ans, l + r + root->val);
        return max(l,r) + root->val;
    }

    if(root->left == NULL){
        return r + root->val;
    }

    if(root->right == NULL){
        return l + root->val;
    }
    return 0;
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
        int ans = INT_MIN;
        cout <<maxSum(root,ans)<<endl;
    }
}

// 1
// 12
// -15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
// => 27
