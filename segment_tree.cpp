/*
    assign N and arr[]. arr is the values
    which which segment tree is made for.
    change func and def accordingly.
*/

int func(int a, int b){
    return a + b;
}
int def = 0;
int arr [mxn], seg_tree[mxn];
int N;

void build(int lo = 0, int hi = N-1, int pos = 1){
    assert(lo <= hi);
    if(lo == hi) {
        seg_tree[pos] = arr[lo]; return;
    }
    int mid = (lo + hi)/2;
    build(lo,mid,2*pos); build(mid+1,hi,2*pos+1);
    seg_tree[pos] = func(seg_tree[2*pos],seg_tree[2*pos+1]);
}

void update(int ind, int val, int lo = 0, int hi = N-1, int pos = 1){ //0 indexed. arr[ind] = val.
    if(lo == hi){
        seg_tree[pos] = val; arr[pos] = val; return;
    }
    int mid = (lo + hi)/2;
    if(mid >= ind) update(ind,val,lo,mid,2*pos);
    else update(ind,val,mid+1,hi,2*pos+1);
    seg_tree[pos] = func(seg_tree[2*pos],seg_tree[2*pos+1]);
}

int query(int l, int r, int pos = 1, int lo = 0, int hi = N-1){ // 0 indexed [l,r].
    if(lo > r || hi < l) return def; //no overlap
    if(lo >= l && hi <= r) return seg_tree[pos]; //total overlap
    int mid = (lo + hi)/2;
    return func(query(l,r,2*pos,lo,mid),query(l,r,2*pos+1,mid+1,hi)); //partial overlap
}
