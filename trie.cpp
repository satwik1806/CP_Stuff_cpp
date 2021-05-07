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
}triex;
triex* head;

void insert(int x){
    triex* curr = head;
    for(int i=31;i>=0;i--){
        int b = (x >> i) & 1;
        if(!curr->bit[b]) curr->bit[b] = new triex();
        curr = curr->bit[b];
        curr->pref_cnt++;
    }
}

void remove(int x){
    triex* curr = head;
    for(int i=31;i>=0;i--){
        int b = (x >> i) & 1;
        curr = curr->bit[b];
        curr->pref_cnt--;
    }
}

int find(int x){
    triex* curr = head;
    int ans = 0;
    for(int i=31;i>=0;i--){
        int b = (x >> i) & 1;
        b = 1 - b;
        if(!curr->bit[b]){
            curr = curr->bit[1-b];
            ans += (1-b)*(power(2,i));
        }
        else{
            curr = curr->bit[b];
            ans += b * power(2,i);
        }
    }

    return ans;
}

void test_case(){
    head = new triex();
    int n; cin >> n;
    int a[n]; for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) insert(a[i]);
    int f,s;
    int curr = -inf;
    for(int i=0;i<n;i++){
        int other = find(a[i]);
        if((other^a[i]) > curr){
            f = other; s = a[i];
            curr = f^s;
        }
    }

    if(f > s) swap(f,s);
    cout << f << " " << s << endl;
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

