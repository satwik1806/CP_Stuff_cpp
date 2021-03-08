// LCA - Lowest Common Ancestor.
// Author - Satwik_Tiwari
// whole graph is 0 indexed and queries as well.
// graph is global as well.

int aa[mxn];
template<typename T>
class RangeQuery {
private:
    vector<vector<T>> data;
public:
    void RangeQuery_precompute(int n) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back(aa[i]);
        }
        data.push_back(temp);
        int i = 1;
        while (2 * i <= n) {
            vector<int> prev = data[size(data) - 1];
            vector<int> put;
            for (int j = 0; j < n - 2 * i + 1; j++) {
                put.push_back(func(prev[j], prev[j + i]));
            }
            data.push_back(put);
            i <<= 1;
        }
    }

    T func(T aaa, T ab) { // change it according to you.
        return min(aaa, ab);
    }

    T query(int st, int end) { // ask queries like query[st,end).
        int bits; int x = end - st;
        for (bits = 0; x != 0; ++ bits) x >>= 1; bits--;
        return (func(data[bits][st], data[bits][end - (1 << bits)]));
    }

    T getitem(int idx) {
        return (data[0][idx]);
    }
};

template<typename T>
class LCA {
private:
    vector<T> time;
    vector<T> path;
    RangeQuery<T> rmq;
public:
    LCA(T root, int n) {
        vector<int> P;
        for (int i = 0; i < n; i++) {
            time.push_back(-1); path.push_back(-1); P.push_back(-1);
        }
        int tt = -1; vector<int> dfs; dfs.push_back(root);
        while (!empty(dfs)) {
            int node = dfs.back(); dfs.pop_back();
            path[tt == -1 ? n - 1 : tt] = P[node];
            time[node] = ++tt;
            for (int nie : g[node]) {
                if (time[nie] == -1) {
                    P[nie] = node;
                    dfs.push_back(nie);
                }
            }
        }
        int ii = 0 ;
        for (int i : path) aa[ii++] = time[i == -1 ? n - 1 : i];
        rmq.RangeQuery_precompute(n);
    }

    T query(int a, int b) {
        if (a == b) return a;
        a = time[a]; b = time[b];
        if (a > b) swap(a, b);
        return path[rmq.query(a, b)];
    }
};