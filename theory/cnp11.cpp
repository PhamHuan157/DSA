// Duyệt BTree PostOrder từ LevelOrder và InOder

#include<bits/stdc++.h>
using namespace std;

int inOrder[1001], levelOrder[1001], mark[10001], n;

void postOrder(int l, int r){
    if(l>r) return; //  trường hợp dừng
    else if(l == r){
        // trường hợp cây con bên trái hoặc cây con bên phải có mỗi một phần tử
        cout <<inOrder[l]<<" ";
    }else{
        int pos; // tìm chỉ số của node gốc cây con hiện tại trong mảng levelOrder
        for(int i=1; i<=n; i++){
            if(mark[levelOrder[i]] >= l and mark[levelOrder[i]] <=r){
                // pos = i;or
                pos = levelOrder[i];
                break;
            }
        }

        // cout <<inOrder[pos]<<" "; ở đây nếu preOrder
        // pos = mark[levelOrder[pos]]; or
        pos = mark[pos]; // tìm chỉ số của pos trong mảng inOrder
        postOrder(l,pos - 1); // tìm sang trái
        postOrder(pos+1, r); // tìm sang phải
        cout <<inOrder[pos]<<" "; // posOrder
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>inOrder[i];
            mark[inOrder[i]] = i;
        }
        for(int i= 1; i<=n; i++){
            cin>>levelOrder[i];
        }
        postOrder(1,n);
        cout <<endl;
    }
}

// 2
// 3
// 1 0 2
// 0 1 2
// => 1 2 0 
// 7
// 3 1 4 0 5 2 6
// 0 1 2 3 4 5 6
// => 3 4 1 5 6 2 0 