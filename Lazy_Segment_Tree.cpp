template<typename T>
class Lazy_segtree{
private:
    vector<T> arr; vector<T> seg_tree,lazy;
    int N; int def;
public:
    // change default accordingly. set for sum intially.
    Lazy_segtree(vector<T> a, int deff = inf){ //make sure not to pass global vector of size = mxn;
        N = a.size();
        def = deff;
        arr = a;
        seg_tree.resize(4*N + 10,0);
        lazy.resize(4*N + 10,0);
        build();
    }

    int func(int a, int b){
        return min(a,b);
    }

    void build(){
        build_it_for_me(0,N-1,1);
    }

    void build_it_for_me(int lo, int hi, int pos){
        assert(lo <= hi);
        if(lo == hi) {
            seg_tree[pos] = arr[lo]; return;
        }
        int mid = (lo + hi)/2;
        build_it_for_me(lo,mid,2*pos); build_it_for_me(mid+1,hi,2*pos+1);
        seg_tree[pos] = func(seg_tree[2*pos],seg_tree[2*pos+1]);
    }

    void update(int l, int r, int val){
        update_it_for_me(l,r,val,0,N-1,1);
    }
    void update_it_for_me(int l, int r, int val, int lo, int hi, int pos){ //0 indexed. arr[ind] = val.
        assert(lo <= hi);
        if (lazy[pos] != 0){
            seg_tree[pos] += lazy[pos];
            if (lo != hi){
                lazy[2 * pos] += lazy[pos];
                lazy[2 * pos + 1] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if (l > hi || r < lo) //no overlap
            return;
        if (l <= lo && r >= hi) {//complete overlap
            seg_tree[pos] += val;
            lazy[pos] += val;
            if (lo != hi){
                lazy[2 * pos] += lazy[pos];
                lazy[2 * pos + 1] += lazy[pos];
            }
            lazy[pos] = 0;
            return;
        }
        int mid = (lo + hi) / 2;
        update_it_for_me(l,r,val,lo,mid,2*pos);update_it_for_me(l,r,val,mid+1,hi,2*pos+1);
        seg_tree[pos] = min(seg_tree[2*pos], seg_tree[2*pos + 1]);
    }

    T query(int l, int r){
        return query_it_for_me(l,r,0,N-1,1);
    }

    T query_it_for_me(int l, int r, int lo, int hi, int pos){ // 0 indexed [l,r].
        if (lazy[pos] != 0){
            seg_tree[pos] += lazy[pos];
            if (lo != hi){
                lazy[2 * pos] += lazy[pos];
                lazy[2 * pos + 1] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if (lo > r || hi < l)
            return INT_MAX;
        if (lo >= l && hi <= r)
            return seg_tree[pos];
        int mid = (lo + hi) / 2;
        int val1 = query_it_for_me(l,r,lo,mid,2*pos);int val2 = query_it_for_me(l,r,mid+1,hi,2*pos+1);
        return min(val1, val2);
    }
};
