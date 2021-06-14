// try to implement it fresh always. just take the idea of implementation from here.

int n,m;
vector<vector<int>> g(mxn,vector<int>());
vector<vector<int>> revg(mxn,vector<int>());
vector<int> group(mxn,-1);
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

void dfs2(int st, int grp){// assigning groups in transpose graph of scc.
    group[st] = grp; vis[st] = 1;
    for(int to: revg[st]){
        if(not vis[to]) dfs2(to,grp);
    }
}

int findscc(){ // return number of scc and assign groups to each node.
    for(int i=0;i<n;i++) vis[i] = 0;
    vector<int> order = topsort();
    for(int i=0;i<n;i++) vis[i] = 0;
    int cnt = 0;
    for(int i: order){
        if(group[i] == -1) dfs2(i,cnt++);
    }
    return cnt;
}

vector<vector<int>> compress_scc(){ // graphs of compressed nodes. (group DAG)
    vector<vector<int>> gr(n,vector<int>());
    for(int i=0;i<n;i++){
        for(auto to: g[i]){
            if(group[i] != group[to]) gr[group[i]].push_back(group[to]);
        }
    }
    return gr;
}
