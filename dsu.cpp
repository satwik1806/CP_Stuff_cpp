class DSU {
private:
    vector<int> comp, siz, sta;
public:
    DSU(int n) : comp(n), siz(n, 1) {
        for (int i = 0; i < n; ++i) comp[i] = i;
    }
    int Find(int i) {
        if (comp[i] != i) return comp[i] = Find(comp[i]);
        else return i;
    }
    bool Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (siz[a] < siz[b]) swap(a, b);

        sta.push_back(b);
        if (a == b) return false;

        siz[a] += siz[b];
        comp[b] = a;
        return true;
    }
    void Undo() {
        int b = sta.back();
        int a = comp[b];
        sta.pop_back();

        if (a != b) siz[a] -= siz[b];
        comp[b] = b;
    }
    int compSize(int i) {
        return siz[Find(i)];
    }
};