// height

#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
int pre[10001],n;
bool used[1001];

void dfs(int u){
    used[u] = true;
    for(int v: ke[u]){
        if(!used[v]){
            pre[v] = pre[u] + 1;
            dfs(v); 
        }
    }
}

int main(){

    cin>>n;
    for(int i=0; i<n-1; i++){
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(used,0,sizeof(used));
    memset(pre,0,sizeof(pre));
    pre[1] = 0;
    dfs(1);
    cout << *max_element(pre,pre+n+1)<<endl;

}