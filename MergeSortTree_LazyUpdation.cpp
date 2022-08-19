/*  Author - Satwik_Tiwari  */

#include<bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
    ~debug() { cerr << endl; }
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair < b, c > d) {
        ris << "(" << d.first << ", " << d.second << ")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        ris << "]";
    }
#else
    sim dor(const c&) { ris; }
#endif
};
#define print(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define int long long
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define minheap priority_queue <int, vector<int>, greater<>>
#define endl "\n"
#define google cout << "Case #" << casee << ": " ;

int power(int x, int y, int M) {int res = 1; x%=M; if(not x) return 0; while (y > 0) {if (y & 1) res = (res * x) % M; y >>= 1; x = (x * x) % M;} return res % M;}
int power(int x, int y) {int res = 1; if(not x) return 0; while (y > 0) {if (y & 1) res = (res * x); y >>= 1; x = (x * x);} return res;}
const int mxn = 1e6 + 6, mod = 998244353, inf = 1e18 ; int t,casee = 1;

template<typename T>
class Segment_Tree{
private:
    struct node{
        int maxlen_left_alt;
        int maxlen_right_alt;
        bool alt;
        int ans;
        int left;
        int right;
        bool flip;
        void deb(){
            debug() << print(maxlen_right_alt) print(maxlen_left_alt);
            debug() << print(alt) print(ans) print(left) print(right) print(flip);
        }
    };
    vector<node> arr; vector<node> seg_tree;
    int N; node def;
public:
    // initiate a new node
    node initiate(int val) {return node{1,1,1,1,val,val,0};}

    // change default accordingly.
    Segment_Tree(vector<T> a){ //make sure not to pass global vector of size = mxn;
        N = a.size(); arr.resize(N);
        for(int i=0;i<N;i++) {
            arr[i] = initiate(a[i]);
        }
        seg_tree.resize(4*N + 10);
        def = node{0,0,1,0,-1,-1,0};
        build();
    }

    node merge(node a, node b){
        node temp;
        if(a.left == -1 or a.right == -1){
            temp = b; return temp;
        }

        if(b.left == -1 or b.right == -1){
            temp = a; return temp;
        }

        // ans
        int currans = a.ans + b.ans;
        if(a.right != b.left){
            currans += a.maxlen_left_alt * b.maxlen_right_alt;
        }
        temp.ans = currans;

        // alt
        if(a.alt and b.alt and a.right != b.left) temp.alt = 1;
        else temp.alt = 0;

        // left and right
        temp.left = a.left;
        temp.right = b.right;

        //maxlen_left
        if(b.alt and b.left != a.right) temp.maxlen_left_alt = b.maxlen_left_alt + a.maxlen_left_alt;
        else temp.maxlen_left_alt = b.maxlen_left_alt;

        //maxlen_right
        if(a.alt and b.left != a.right) temp.maxlen_right_alt = a.maxlen_right_alt + b.maxlen_right_alt;
        else temp.maxlen_right_alt = a.maxlen_right_alt;

        temp.flip = 0;
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

//    void update(int ind, int val){
//        update_it_for_me(ind,val,0,N-1,1);
//    }
//    void update_it_for_me(int ind, T val, int lo, int hi, int pos){ //0 indexed. arr[ind] = val.
//        if(lo == hi){
//            seg_tree[pos] = initiate(val);
//            arr[ind] = initiate(val); return;
//        }
//        int mid = (lo + hi)/2;
//        if(mid >= ind) update_it_for_me(ind,val,lo,mid,2*pos);
//        else update_it_for_me(ind,val,mid+1,hi,2*pos+1);
//        seg_tree[pos] = merge(seg_tree[2*pos],seg_tree[2*pos+1]);
//    }

    void update(int l, int r){
        update_it_for_me(l,r,0,N-1,1);
    }
    void update_it_for_me(int l, int r, int lo, int hi, int pos){ //0 indexed. arr[ind] = val.
        if(lo >= l and hi <= r){//total overlap
            seg_tree[pos].right = 1 - seg_tree[pos].right;
            seg_tree[pos].left = 1 - seg_tree[pos].left;
            seg_tree[pos].flip = 1 - seg_tree[pos].flip;
            return;
        }
        if(seg_tree[pos].flip){
            // we need to flip below ones.
            for(int i: {2*pos, 2*pos + 1}){
                seg_tree[i].left = 1 - seg_tree[i].left;
                seg_tree[i].right = 1 - seg_tree[i].right;
                seg_tree[i].flip = 1 - seg_tree[i].flip;
            }
            seg_tree[pos].flip = 0;
        }
        int mid = (lo + hi)/2;
        if(mid >= l) update_it_for_me(l,r,lo,mid,2*pos);
        if(mid < r) update_it_for_me(l,r,mid + 1, hi,2*pos + 1);
        seg_tree[pos] = merge(seg_tree[2*pos],seg_tree[2*pos+1]);
    }

    node query(int l, int r){
        return query_it_for_me(l,r,1,0,N-1);
    }

    node query_it_for_me(int l, int r, int pos, int lo, int hi){ // 0 indexed [l,r].
        if(lo > r || hi < l || r < l) return def; //no overlap
        if(lo >= l && hi <= r) return seg_tree[pos]; //total overlap
        int mid = (lo + hi)/2;
        if(seg_tree[pos].flip){
            // we need to flip below ones.
            for(int i: {2*pos, 2*pos + 1}){
                seg_tree[i].left = 1 - seg_tree[i].left;
                seg_tree[i].right = 1 - seg_tree[i].right;
                seg_tree[i].flip = 1 - seg_tree[i].flip;
            }
            seg_tree[pos].flip = 0;
        }
        return merge(query_it_for_me(l,r,2*pos,lo,mid),query_it_for_me(l,r,2*pos+1,mid+1,hi)); //partial overlap
    }
};

void test_case() {
    int n,q; cin >> n >> q;
    vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];

    Segment_Tree<int> segtree(a);

    for(int i=0;i<q;i++){
        int type; cin >> type;
        int l,r; cin >> l >> r;
        l--; r--;
        if(type - 1){
            cout << segtree.query(l,r).ans << endl;
        }
        else{
//            for(int j=l;j<=r;j++) segtree.update(j,(segtree.query(j,j).left ^ 1));
            segtree.update(l,r);
        }
    }
}

int32_t main() {
    FastIO;
    t = 1;
//    cin >> t;
    while (t--) {
        test_case();
        casee++;
    }
    return 0;
}
















