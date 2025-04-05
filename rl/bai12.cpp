// duong di tu node la

#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
int n, pre[10001];
vector<int> ds;
bool visited[1001];

void dfs(int u){
    visited[u] = true;
    for(int v: ke[u]){
        if(!visited[v]){
            pre[v] = u;
            dfs(v);
        }
    }
}

void path(int v, int u){
    vector<int> path;
    while(u!=v){
        path.push_back(u);
        u = pre[u];
    }
    path.push_back(v);
    reverse(path.begin(), path.end());
    for(int x: path) cout <<x<<" ";
    cout <<endl;
}


int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited,0,sizeof(visited));
    for(int i=2; i<=n; i++){
        if(ke[i].size() == 1){
            ds.push_back(i);
        }
    }
    dfs(1);
    for(int x: ds){
        path(1,x);
    }

}