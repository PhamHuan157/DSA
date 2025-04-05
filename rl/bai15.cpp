//Inorder or not

#include<bits/stdc++.h>
using namespace std;

int main(){
    // int t; cin>>t;
    int t = 1;
    while(t--){
        int n; cin>>n;
        int in[n];
        for(int i=0; i<n; i++) cin>>in[i];

        bool yes = true;
        for(int i=1; i<n; i++){
            if(in[i] <= in[i-1]){
                yes = false;
                break;
            }
        }
        if(yes) cout <<1<<endl;
        else cout <<0<<endl;
    }
}