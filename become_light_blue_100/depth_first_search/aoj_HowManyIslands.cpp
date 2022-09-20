/**
 *    author:  USERNAME
 *    create-mm-dd hh:mm:ss
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
int vec4[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int vec8[8][2] = {{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};

int w, h;
int field[50][50]={};
int main() {
    // code
    cin >> w >> h;
    rep(hh, h) {
        rep(ww, w) { cin >> field[h][w]; }
    }

    return 0;
}