// Cho mảng chứa cách duyệt của BST, kiểm tra nó có được duyệt theo inOrder hay không
// Chú ý: InOrder luôn cho thứ tự tăng dần

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int inOrder[n];
        // map<int, bool> mp;
        bool ok = true;

        for(int i =0; i<n; i++){
            cin>>inOrder[i];
        }
        // mp[inOrder[0]]= true;
        for(int i = 1; i<n; i++){
            if(inOrder[i] <= inOrder[i-1]){
                ok =false;
                break;
            }
            // mp[inOrder[i]]++;
        }
        if(ok) cout<<1<<endl;
        else cout <<0<<endl;
    }
}

// 3  
// 5
// 10 20 30 40 50
// => 1
// 6
// 90 80 100 70 40 30
// => 0
// 3
// 1 1 2
// => 0

