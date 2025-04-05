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

void makeRoot(Node* root, int u, int v, char c){
	if(c == 'L') root->left = new Node(v);
	else root->right = new Node(v);
}

void Insert(Node* root, int u, int v, char c){
	if(root == NULL) return;
	if(root->val == u){
		makeRoot(root,u,v,c);
		return;
	}
	Insert(root->left,u,v,c);
	Insert(root->right,u,v,c);
}

void preOrder(Node* root){
	if(root == NULL) return;
	cout <<root->val<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root){
	if(root== NULL) return;
	inOrder(root->left);
	cout <<root->val<<" ";
	inOrder(root->right);
}

void postOrder(Node* root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout <<root->val<<" ";
}

void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	while(q.size()){
		Node* top = q.front(); q.pop();
		cout <<top->val<<" ";
		if(top->left != NULL) q.push(top->left);
		if(top->right != NULL) q.push(top->right);
	}
}

int height(Node* root){
	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

void spiralOrder(Node* root){
	stack<Node*> st1;
	stack<Node*> st2;
	st1.push(root);
	while(st1.size()){
		Node* top = st1.top(); st1.pop();
		cout<<top->val<<" ";
		if(top->right != NULL) st2.push(top->right);
		if(top->left != NULL) st2.push(top->left);
	}
	while(st2.size()){
		Node* top = st2.top(); st2.pop();
		cout <<top->val<<" ";
		if(top->left != NULL) st1.push(top->left);
		if(top->right != NULL) st2.push(top->right);
	}
}
// Cay avl

Node* makeTree(int a[], int l, int r){
	if(l>r) return NULL;
	int m = (l+r)/2;
	Node* root = new Node(a[m]);
	root->left = makeTree(a,l,m-1);
	root->right = makeTree(a,m,r);
	return root;
}

// cay bst

Node* makeBranch(int a[],int *idx, int l, int r, int n){
	if(*idx >=n or l>r ) return NULL;
	Node* root = new Node(a[*idx]);
	++(*idx);
	if(l == r) return root;
	int ans =r;
	for(int i=l; i<=r; i++){
		if(a[i] > root->val){
			ans = i;
			break;
		}
	}
	root->left = makeBranch(a,idx,*idx,ans-1, n);
	root->right = makeBranch(a,idx,ans,r,n);
	return root;
}

int main(){
	Node* root = NULL;
	int n; cin>>n;
	for(int i=0; i<n; i++){
		int u,v; char c; cin>>u>>v>>c;
		if(root == NULL){
			root = new Node(u);
			makeRoot(root,u,v,c);
		}else{

		}
	}
}