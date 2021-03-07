//dijkstra algorithm to find distances of all nodes from a single source
// author - Satwik_tiwari
#define minheap priority_queue <pair<int,int>, vector<pair<int,int>>, greater<>>
vector<int> dijkstra(int st) {
    vector<int> dist(n, inf), par(n, -1);
    dist[st] = 0;
    minheap heap;
    heap.push({0, st});
    while (!empty(heap)) {
        pair<int, int> temp = heap.top(); heap.pop();
        int path_len = temp.ff, v = temp.ss;
        if (path_len == dist[v]) {
            for (auto ii : g[v]) {
                int w = ii.ff, edge_len = ii.ss;
                if (edge_len + path_len < dist[w]) {
                    dist[w] = edge_len + path_len;
                    par[w] = v;
                    heap.push({dist[w], w});
                }
            }
        }
    }
    return dist;
}