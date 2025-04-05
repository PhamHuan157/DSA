// Duyệt cây và tìm đường đi từ 1 gốc (size = 1) đến node gốc (1);

#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
int n, pre[1001];
bool used[1001];
vector<int> leaf;

void dfs(int u){
    used[u] = true;
    for(int v: ke[u]){
        if(!used[v]){
            pre[v] = u;
            dfs(v);
        }
    }
}

void path(int u, int v){
    vector<int> pth;
    
    while(v != u){
        pth.push_back(v);
        v = pre[v];    
    }
    pth.push_back(u);
    reverse(pth.begin(), pth.end());
    for(int x: pth) cout<<x<<" ";
    cout <<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        memset(used,0,sizeof(used));
        for(int i=0; i<n-1; i++){
            int x,y;cin >>x>>y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        dfs(1);
        int cnt = 0;
        for(int i =2; i<=n; i++){
            if(ke[i].size() == 1){
                leaf.push_back(i);
            }
        }

        for(int x: leaf){
            path(1, x);
        }
        for(int i=1; i<=n; i++) ke[i].clear();
        leaf.clear();
    }
    
}

// 2
// 5
// 1 2   
// 1 3
// 2 4
// 2 5
// 1 3   
// => 1 2 4 
// => 1 2 5
// 4
// 1 2
// 2 3
// 3 4
// => 1
// => 1 2 3 4
