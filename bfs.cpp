int vis[mxn];
void bfs(int st) {
    vis[st] = 1;
    deque<int> deq; vector<int> order;
    deq.push_back(st);
    while (deq.size() != 0) {
        int s = deq.front(); deq.pop_front();
        order.push_back(s);
        for (int i : g[s]) {
            if (!vis[i]) {
                vis[i] = 1;
                deq.push_back(i);
            }
        }
    }

    //print order
    for (int i : order) cout << i << " ";
}