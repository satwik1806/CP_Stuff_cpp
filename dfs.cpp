vector<int> order;
void dfs(int st, bool vis) { //pass graph as argument if required
	vis[st] = true; order.pb(st);
	for (auto i : g[st]) {
		if (!vis[i])
			dfs(i, vis);
	}
}