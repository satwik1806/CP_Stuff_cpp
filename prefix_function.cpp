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
#define minheap priority_queue <int, vector<int>, greater<>>
#define endl "\n"
#define google cout << "Case #" << casee << ": " ;

int power(int x, int y, int M) {int res = 1; while (y > 0) {if (y & 1) res = (res * x) % M; y >>= 1; x = (x * x) % M;} return res % M;}
int power(int x, int y) {int res = 1; while (y > 0) {if (y & 1) res = (res * x); y >>= 1; x = (x * x);} return res;}
const int mxn = 1e6 + 6, mod = 1e9+7, inf = 1e18 ; int t,casee = 1;

vector<int> prefix_function(string s) { // pre[i] is the max length prefix also present in suffix of s[0:i].
    int n = s.size();
    vector<int> pre(n);
    for (int i = 1; i < n; i++) {
        int j = pre[i-1];
        while (j > 0 && s[i] != s[j])
            j = pre[j-1];
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
    return pre;
}

void test_case() {
    // find no of occurence of find in s.
    string s; cin >> s;
    string find; cin >> find;
    vector<int> temp = prefix_function(find + "*" + s); // adding a separator. so that pre[i] <= find.size().
    int cnt = 0;
    for(int i=find.size() + 1;i<temp.size();i++){
        if(temp[i] == find.size()) cnt++;
    }
    cout << cnt << endl;
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

