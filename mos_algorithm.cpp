/*    Author - Satwik_Tiwari  */

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define minheap priority_queue <ll, vector<ll>, greater<>>
#define endl "\n"
#define mem(a , b) memset(a , b , sizeof(a))
#define itos to_string
#define google cout << "Case #" << casee << ": " ;

#define debug(a) cerr << #a << ": "; _print(a); cerr << endl; cerr.flush();
#define debugarr(a,n) cerr << #a << ": "; _print(a,n); cerr << endl;

typedef unsigned long long ull;
typedef long double ldb;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ldb t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template<class T> void _print(deque <T> deq) {cerr << "[ "; for (T i : deq) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(int a[],int n) {cerr << "[ "; for(int i=0;i<n;i++){_print(a[i]); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int power(int x, int y, int M) {int res = 1; while (y > 0) {if (y & 1) res = (res * x) % M; y >>= 1; x = (x * x) % M;} return res % M;}
int power(int x, int y) {int res = 1; while (y > 0) {if (y & 1) res = (res * x); y >>= 1; x = (x * x);} return res;}
const int mxn = 3e5 + 6, mod = 1e9+7, inf = 1e18 ; int t,casee = 1;

int a[mxn]; int n,queries;
int sz; //sqrt(n).
int ans = 0; //my current answer.
int curr_freq[mxn]; //stores the current freq.
int cnt_of_freq[mxn]; //store the freq of freq.
int ans_queries[mxn]; //stores answer to queries offline.

struct query{
    int l,r,id;

    bool operator<(const query &aa) const{
        int x = l/sz;
        int y = aa.l/sz;

        if(x == y) return r < aa.r; //if in same block.
        return x < y; //else sort it by block number.
    }
} q[mxn];

void add(int val){ // increases the freq of the element in logn,
    cnt_of_freq[curr_freq[val]]--;
    curr_freq[val] ++;
    cnt_of_freq[curr_freq[val]]++;
    if(curr_freq[val] > ans) ans = curr_freq[val];
}

void remove(int val){ //decreases the freq of the element in logn.
    if(ans == curr_freq[val] and cnt_of_freq[curr_freq[val]] == 1) ans = curr_freq[val]-1;
    cnt_of_freq[curr_freq[val]]--;
    curr_freq[val] --;
    cnt_of_freq[curr_freq[val]]++;
}

void mos_algo(){

    sort(q,q + queries); //sorting all the queries.
    //first according to the blocks. and then by ascending
    //right segment for the same block (size sqrt n).

    // answering queries;
    int l = 0; int r = -1;
    for(int i=0;i<queries;i++){
        while(l < q[i].l) remove(a[l++]);
        while(l > q[i].l) add(a[--l]);
        while(r < q[i].r) add(a[++r]);
        while(r > q[i].r) remove(a[r--]);
        ans_queries[q[i].id] = ans;
    }
}

void test_case() {
    cin >> n >> queries;
    sz = sqrt(n);

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<queries;i++){
        int l,r ; cin >> l >> r;
        q[i].l = l; q[i].r = r; q[i].id = i;
    }

    mos_algo();
    // output the ans to the queries;
    for(int i=0;i<queries;i++) cout << ans_queries[i] << endl;
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

