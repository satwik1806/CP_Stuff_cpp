/*
  make graph global.
*/

vector<int> tour;
void dfs(int st, int par){
    tour.push_back(st);
    for(int i:g[st]){
        if(i == par) continue;
        dfs(i,st);
    }
    tour.push_back(st);
}
