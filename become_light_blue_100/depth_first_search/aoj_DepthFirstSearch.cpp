/**
 *    author:  USERNAME
 *    create-mm-dd hh:mm:ss
 * 感想
 * 探索済みフラグは最初にtrueにしないと自己参照があったり、ループがあったりするので死ぬ
 * インデックスのミスが多い、最初に0からに全部変換したほうがいいと思う。
 **/

#include <bits/stdc++.h>
using namespace std;

/* alias */
#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<int, int>

/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool)            \
    if (bool) {                \
        cout << "YES" << endl; \
    } else {                   \
        cout << "NO" << endl;  \
    }
#define yesno(bool)            \
    if (bool) {                \
        cout << "yes" << endl; \
    } else {                   \
        cout << "no" << endl;  \
    }
#define YesNo(bool)            \
    if (bool) {                \
        cout << "Yes" << endl; \
    } else {                   \
        cout << "No" << endl;  \
    }

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x)                                                    \
    cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x \
         << "\033[m" << endl;

/* func */
inline int in_int() {
    int x;
    cin >> x;
    return x;
}
inline ll in_ll() {
    ll x;
    cin >> x;
    return x;
}
inline string in_str() {
    string x;
    cin >> x;
    return x;
}

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T>
inline bool chmin(T& a, const T& b) {
    bool compare = a > b;
    if (a > b) a = b;
    return compare;
}
template <typename T>
inline bool chmax(T& a, const T& b) {
    bool compare = a < b;
    if (a < b) a = b;
    return compare;
}
// gcd lcm
// C++17からは標準実装
// template <typename T> T gcd(T a, T b) {if (b == 0)return a; else return
// gcd(b, a % b);} template <typename T> inline T lcm(T a, T b) {return (a * b)
// / gcd(a, b);}
// clang-format on

void sol(vvi &nei_ls, vvi &ans, int &time,vector<bool> &nodes_fin, int node){
    ++time;
    ans[node][0] = time;
    nodes_fin[node] = true;
    rep(i,nei_ls[node].size()){
        if (!nodes_fin[nei_ls[node][i]]){
            sol(nei_ls, ans, time, nodes_fin, nei_ls[node][i]);
        }
    }
    ++time;
    ans[node][1] = time;
}
int main() {
    int n = in_int();
    vvi nei_ls(n);
    rep(i,n){
        in_int();
        int nei_num = in_int();
        vi neis(nei_num);
        rep(k,nei_num){ neis[k] = in_int()-1;}
        nei_ls[i] = neis;
    }
    vvi ans(n,vi(2,0));
    vector<bool> nodes_fin(n,false);
    int time=0;
    rep(i,n){
        if(!nodes_fin[i]) sol(nei_ls, ans, time, nodes_fin, i);
    }
    rep(i,n){
        cout << i+1 << " " << ans[i][0] << " " << ans[i][1] <<endl;
    }
    return 0;
}