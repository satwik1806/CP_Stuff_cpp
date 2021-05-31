/*    Author - Satwik_Tiwari  */

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
#define minheap priority_queue <ll, vector<ll>, greater<>>
#define endl "\n"
#define mem(a , b) memset(a , b , sizeof(a))
#define itos to_string
#define google cout << "Case #" << casee << ": " ;

int power(int x, int y, int M) {int res = 1; while (y > 0) {if (y & 1) res = (res * x) % M; y >>= 1; x = (x * x) % M;} return res % M;}
int power(int x, int y) {int res = 1; while (y > 0) {if (y & 1) res = (res * x); y >>= 1; x = (x * x);} return res;}
const int mxn = 1e6 + 6, mod = 1e9+7, inf = 1e18 ; int t,casee = 1;

typedef struct data
{
    data* bit[2];
    int pref_cnt = 0; //0 means nothing here
    bool complete = false;
}trie;
trie* head;

void insert(int x){
    trie* curr = head;
    for(int i=3;i>=0;i--){
        int b = (x >> i) & 1;
        if(!curr->bit[b]) curr->bit[b] = new trie();
        curr = curr->bit[b];
        curr->pref_cnt++;
    }
}

void remove(int x){
    trie* curr = head;
    for(int i=3;i>=0;i--){
        int b = (x >> i) & 1;
        curr = curr->bit[b];
        curr->pref_cnt--;
    }
}

int find(int x){
    trie* curr = head;
    int ans = 0;
    for(int shift = 3; shift >= 0; shift--){
        int b = (x >> shift) & 1;
        if(not curr->bit[b] or curr->bit[b]->pref_cnt == 0){
            return ans-1;
        }
        else{
            int leafs = (1ll << shift);
            if(curr->bit[b]->pref_cnt == leafs){
                if(curr->bit[1-b] and curr->bit[1-b]->pref_cnt) {
                    curr = curr->bit[1 - b];
                    ans |= (1ll << shift);
                }
                else curr = curr->bit[b];
            }
            else{
                curr = curr->bit[b];
            }
        }
    }
    return ans;
}

/*
it will be really better not to insert element greater than 1e6.
as its just useless if you're just inserting 1e6 numbers.
*/


void test_case() {
    head = new trie();
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    unordered_map<int,int> cnt;
    for(int i=0;i<n;i++){
        if(cnt[a[i]]) cnt[a[i]]++; // dont insert dublicate elements.
        else {
            insert(a[i]); cnt[a[i]]++;
        }
    }

    // queries like change a[ind] to val and find mex.
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int ind, val; cin >> ind >> val; ind--;
        if(cnt[a[ind]] == 1){
            remove(a[ind]); insert(val); cnt[a[ind]]--; cnt[val]++; a[ind] = val;
        }
        else cnt[a[ind]]--;
        cout << find(0) + 1 << endl;
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
