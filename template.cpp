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

#define debug(a) cerr << #a << ": "; _print(a); cerr << endl;
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
const int mxn = 1e6 + 6 ; int t, mod = 1000000007, inf = 1e18,casee = 1;


void test_case() {

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

