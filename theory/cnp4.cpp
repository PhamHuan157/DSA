// Duyệt cây PostOrder (Duyệt sau) từ PreOrder (Duyệt trước) và InOrder (Duyệt giữa)

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

// Tìm chỉ số của node x trog InOrder, chỉ số của gốc cây
int Search(int in[], int x, int n){
    for(int i=0; i<n; i++){
        if(in[i] == x){
            return i;
        }
    }
    return -1;
}

// Thứ tự inOrder, preOrder và số lượng Node ban đầu của cây
void postOrder(int in[], int pre[], int n){
    // Giá trị của gốc cây bao giờ cũng là phần tủ đầu tiên trong mảng InOrder => pre[0]
    int root = Search(in, pre[0], n); 
    if(root != 0){
        // Dịch con trỏ pre sang bên phải (?)
        postOrder(in,pre+1, root);
    }
    if(root != n - 1){
        postOrder(in+root+1, pre+root+1,n - root - 1);
    }
    cout <<pre[0]<<" ";
}


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int in[n];
        for(int i=0; i<n; i++) cin>>in[i];
        int pre[n];
        for(int i=0; i<n; i++) cin>>pre[i];

        postOrder(in, pre,n);
    }
}

// 1
// 6
// 4 2 5 1 3 6
// 1 2 4 5 3 6
// => 4 5 2 6 3 1