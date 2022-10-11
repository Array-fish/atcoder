/**
 *    author:  USERNAME
 *    create-mm-dd hh:mm:ss
 * 通過済みマップをどっかで持たないときつい。
 * 隣接リストであらわされている時で有向グラフの時は処理をする
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
void erase_parent(int idx, int parent_idx, vvi& conn) {
    rep(i, conn[idx].size()) {
        if (conn[idx][i] == parent_idx) {
            conn[idx].erase(conn[idx].begin() + i);
            break;
        }
    }
    rep(i, conn[idx].size()) {
        erase_parent(conn[idx][i], idx, conn);
    }
}
int main() {
    // code
    int n = in_int();
    vvi conn(n);
    rep(i, n) {
        vi aconn;
        in_int();
        int m = in_int();
        rep(i, m) { aconn.pb(in_int() - 1); }
        conn[i] = aconn;
    }
    rep(i,conn[0].size()){
        erase_parent(conn[0][i],0,conn);
    }
    vi ans(n, -1);
    ans[0] = 0;
    deque<int> deq;
    deq.push_back(0);
    while (deq.size() > 0) {
        int idx = deq.front();
        deq.pop_front();
        rep(i, conn[idx].size()) {
            if (ans[conn[idx][i]] == -1){
                ans[conn[idx][i]] = ans[idx] + 1;
                deq.push_back(conn[idx][i]);
            }
        }
    }
    rep(i, n) { cout << i + 1 << " " << ans[i] << endl; }
    return 0;
}