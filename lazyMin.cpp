#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ll long long
#define pb push_back
#define lcm(a, b) a *b / __gcd(a, b)
#define endl "\n"
#define start()                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define lop(i, n) for (int i = 0; i < n; i++)
#define f first
#define sec second
// #define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

bool myfnc(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.f > b.f;
}
bool myfnc1(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.f > b.f;
}
bool sortbysec(const tuple<int, int, int> &a,
               const tuple<int, int, int> &b)
{
    // if(get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    return (get<0>(a) < get<0>(b));
}
struct compare_first
{
    bool operator()(const pair<int, char> &p, const int &x) const
    {
        return p.first < x;
    }
    bool operator()(const int &x, const pair<int, char> &p) const
    {
        return x < p.first;
    }
};

inline void in(int &x) { scanf("%d", &x); }
inline void outN(int &x) { printf("%d\n", x); }
inline void outS(int &x) { printf("%lld ", x); }
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

bool bit(int n, int k)
{
    if (n & (1LL << k))
        return true;
    return false;
}

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        auto h1 = std::hash<T1>{}(pair.first);
        auto h2 = std::hash<T2>{}(pair.second);

        std::size_t seed = h1;
        seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        return seed;
    }
};

const int mx = 3e5 + 3;
int seg[4 * mx];
int lazy[4 * mx];

void push(int si, int ss, int se)
{
    if (lazy[si] != INT_MAX)
    {
        seg[si] = min(seg[si], lazy[si]);

        if (ss != se)
        {
            lazy[si * 2] = min(lazy[si * 2], lazy[si]);
            lazy[si * 2 + 1] = min(lazy[si * 2 + 1], lazy[si]);
        }
        lazy[si] = INT_MAX;
    }
}

int queryMn(int si, int ss, int se, int qs, int qe)
{

    push(si, ss, se);

    if (ss > qe || se < qs)
        return INT_MAX;

    if (ss >= qs && se <= qe)
    {

        // cout<<si<<" "<<seg[si]<<endl;
        return seg[si]; // Fully within range
    }

    int mid = (ss + se) / 2;
    return min(queryMn(2 * si, ss, mid, qs, qe), queryMn(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int l, int r, int val)
{
    push(si, ss, se);

    if (se < l || ss > r)
        return;

    if (ss >= l && se <= r)
    {
        seg[si] = min(seg[si], val);
        if (ss != se)
        {
            lazy[si * 2] = min(lazy[si * 2], val);
            lazy[si * 2 + 1] = min(lazy[si * 2 + 1], val);
        }
        return;
    }

    int mid = (ss + se) / 2;
    update(si * 2, ss, mid, l, r, val);
    update(si * 2 + 1, mid + 1, se, l, r, val);
    seg[si] = min(seg[si * 2], seg[si * 2 + 1]);
}

void solve(int tc)
{
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    cin >> t;
    //  in(t);
    //  cin.ignore();

    //   start();
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}
