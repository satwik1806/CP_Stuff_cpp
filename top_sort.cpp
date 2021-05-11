int vis[mxn];
void dfs(int st, vector<int> &top){
    vis[st] = 1;
    for(int to: g[st]){
        if(not vis[to]) dfs(to,top);
    }
    top.push_back(st);
}

vector<int> topsort(){
    vector<int> top;
    for(int i=0;i<n;i++){
        if(not vis[i]){
            dfs(i,top);
        }
    }
    reverse(all(top));
    return top;
}
