template<typename T>
class Segment_Tree{
private:
    struct node{
        T sum;
        T maxpref;
        T maxsuff;
        T mx;
        T mn;
        T maxsubarray;
        void debugger(){
            debug() << print(sum) print(maxpref) print(maxsuff) print(mx) print(mn) print(maxsubarray);
        }
    };
    vector<node> arr; vector<node> seg_tree;
    int N; node def;
public:
    // change default accordingly.
    Segment_Tree(vector<T> a){ //make sure not to pass global vector of size = mxn;
        N = a.size(); arr.resize(N);
        for(int i=0;i<N;i++) {
            arr[i] = node{a[i], a[i], a[i], a[i], a[i], a[i]};
        }
        seg_tree.resize(4*N + 10);
        def = node{0,-inf,-inf,-inf,inf,-inf};
        build();
    }

    node merge(node a, node b){
        node temp;
        temp.sum = a.sum + b.sum;
        temp.maxpref = max((T)0,max(a.maxpref,a.sum + b.maxpref));
        temp.maxsuff = max((T)0,max(b.maxsuff,b.sum + a.maxsuff));
        temp.mx = max(a.mx,b.mx);
        temp.mn = min(a.mn,b.mn);
        temp.maxsubarray = max(max((T)0,a.maxsuff) + max((T)0,b.maxpref),max(a.maxsubarray,b.maxsubarray));
        return temp;
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
        seg_tree[pos] = merge(seg_tree[2*pos],seg_tree[2*pos+1]);
    }

    void update(int ind, int val){
        update_it_for_me(ind,val,0,N-1,1);
    }
    void update_it_for_me(int ind, T val, int lo, int hi, int pos){ //0 indexed. arr[ind] = val.
        if(lo == hi){
            seg_tree[pos] = node{val,val,val,val,val,val};
            arr[ind] = {val,val,val,val,val,val}; return;
        }
        int mid = (lo + hi)/2;
        if(mid >= ind) update_it_for_me(ind,val,lo,mid,2*pos);
        else update_it_for_me(ind,val,mid+1,hi,2*pos+1);
        seg_tree[pos] = merge(seg_tree[2*pos],seg_tree[2*pos+1]);
    }

    node query(int l, int r){
        return query_it_for_me(l,r,1,0,N-1);
    }

    node query_it_for_me(int l, int r, int pos, int lo, int hi){ // 0 indexed [l,r].
        if(lo > r || hi < l || r < l) return def; //no overlap
        if(lo >= l && hi <= r) return seg_tree[pos]; //total overlap
        int mid = (lo + hi)/2;
        return merge(query_it_for_me(l,r,2*pos,lo,mid),query_it_for_me(l,r,2*pos+1,mid+1,hi)); //partial overlap
    }
};
