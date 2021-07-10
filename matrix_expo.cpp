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

int expo(int a, int b){
    int res = 1;
    int mul = a;

    for(int i=0;i<32;i++){
        if((b >> i) & 1){
            res*=mul;
        }
        mul*=mul;
    }
    return res;
}

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> res(3,vector<int>(3,0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<int>> mat_expo(vector<vector<int>> a, int b){
    vector<vector<int>> res = {{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int>> mul = a;
    for(int i=0;i<32;i++){
        if((b >> i) & 1){
            res = multiply(res,mul);
        }
        mul = multiply(mul,mul);
    }
    return res;
}

void test_case() {
    int n; cin >> n;
    if(n == 0 or n == 1 or n == 2) cout << 1 << endl;
    else{
        vector<vector<int>> mat = {{1,0,1},{1,0,0},{0,1,0}};
        vector<vector<int>> ans = mat_expo(mat,n-2);
        int sum = 0;
        for(int i=0;i<3;i++) sum += ans[0][i], sum%=mod;
        cout << sum << endl;
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

