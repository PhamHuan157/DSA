// Cây biểu thức (trung tố, tiền tố, hậu tố)
// lưu ý: inOrder bao giờ cũng cho ra thứ tự tăng dần
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char c;
    Node* left, *right;
    Node(char x){
        c = x;
        left = right = NULL;
    }
};

bool check(char c){
    return c =='+' or c== '-' or c =='*' or c =='/';
}
// Duyệt giữa (sẽ ra biểu thức trung tố)
void inOrder(Node* root){
    if(root == NULL) return; // dừng
    inOrder(root->left);
    cout <<root->c;
    inOrder(root->right);
}

// Duyệt trước (sẽ ra biểu thức tiền tố)
void preOrder(Node* root){
    if(root == NULL) return; // dừng
    cout <<root->c;
    preOrder(root->left);
    preOrder(root->right);
}

// Duyệt sau 
void postOrder(Node* root){
    if(root == NULL) return; 
    postOrder(root->left);
    postOrder(root->right);
    cout <<root->c;
}

void solve(string s){
    // lưu các node
    stack<Node*> st;
    Node* root;
    for(int i=0; i<s.size(); i++){
        if(!check(s[i])){
            st.push(new Node(s[i]));
        }else{
            Node* tmp = new Node(s[i]);
            Node* t1 = st.top(); st.pop();
            Node* t2 = st.top(); st.pop();
            tmp->left = t2;
            tmp->right = t1;
            st.push(tmp);
        }
    }

    root = st.top();
    inOrder(root);
    preOrder(root);
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        solve(s);
        cout <<endl;
    }

}

// 2
// ab+ef*g*-
// => a+b-e*f*g
// wlrb+-*
// => w*l-r+b

