template<typename T>
class Segment_Tree{
private:
    vector<T> arr; vector<T> seg_tree;
    int N; int def;
public:
    // change default accordingly. set for sum intially.
    Segment_Tree(vector<T> a, int deff = 0){ //make sure not to pass global vector of size = mxn;
        N = a.size();
        def = deff;
        arr = a;
        seg_tree.resize(4*N + 10,0);
        build();
    }

    int func(int a, int b){
        return a + b;
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

    void update(int ind, int val){
        update_it_for_me(ind,val,0,N-1,1);
    }
    void update_it_for_me(int ind, int val, int lo, int hi, int pos){ //0 indexed. arr[ind] = val.
        if(lo == hi){
            seg_tree[pos] = val; arr[pos] = val; return;
        }
        int mid = (lo + hi)/2;
        if(mid >= ind) update_it_for_me(ind,val,lo,mid,2*pos);
        else update_it_for_me(ind,val,mid+1,hi,2*pos+1);
        seg_tree[pos] = func(seg_tree[2*pos],seg_tree[2*pos+1]);
    }

    T query(int l, int r){
        return query_it_for_me(l,r,1,0,N-1);
    }

    T query_it_for_me(int l, int r, int pos, int lo, int hi){ // 0 indexed [l,r].
        if(lo > r || hi < l) return def; //no overlap
        if(lo >= l && hi <= r) return seg_tree[pos]; //total overlap
        int mid = (lo + hi)/2;
        return func(query_it_for_me(l,r,2*pos,lo,mid),query_it_for_me(l,r,2*pos+1,mid+1,hi)); //partial overlap
    }
};
