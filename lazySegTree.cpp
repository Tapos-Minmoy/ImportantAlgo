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

const int mx = 1e5 + 2;
int seg[4 * mx];
int lazy[4 * mx];

const int inf = INT_MAX;

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        seg[si] = ss; // Change based on the initial value needed
        return;
    }

    int mid = (ss + se) / 2;
    build(si * 2, ss, mid);
    build(si * 2 + 1, mid + 1, se);

    seg[si] = min(seg[si * 2], seg[si * 2 + 1]); // Initialize segment tree
}

void propagate(int si, int ss, int se)
{
    if (lazy[si] != inf)
    {
        seg[si] = min(seg[si], lazy[si]);

        if (ss != se)
        { // Propagate lazy to children
            lazy[si * 2] = min(lazy[si * 2], lazy[si]);
            lazy[si * 2 + 1] = min(lazy[si * 2 + 1], lazy[si]);
        }
        lazy[si] = inf; // Reset lazy value after propagation
    }
}

void update(int si, int ss, int se, int l, int r, int v)
{
    propagate(si, ss, se); // Apply pending lazy updates

    if (ss > r || se < l)
        return;

    if (ss >= l && se <= r)
    {
        seg[si] = min(seg[si], v);
        if (ss != se)
        {
            lazy[si * 2] = min(lazy[si * 2], v);
            lazy[si * 2 + 1] = min(lazy[si * 2 + 1], v);
        }
        return;
    }

    int mid = (ss + se) / 2;
    update(si * 2, ss, mid, l, r, v);
    update(si * 2 + 1, mid + 1, se, l, r, v);

    seg[si] = min(seg[si * 2], seg[si * 2 + 1]); // Update current segment value
}

int query(int si, int ss, int se, int l, int r)
{
    propagate(si, ss, se); // Apply pending lazy updates

    if (ss > r || se < l)
        return inf; // Return max value if range doesn't overlap

    if (ss >= l && se <= r)
    {
        return seg[si]; // Return the segment value within range
    }

    int mid = (ss + se) / 2;
    int leftQuery = query(si * 2, ss, mid, l, r);
    int rightQuery = query(si * 2 + 1, mid + 1, se, l, r);

    return min(leftQuery, rightQuery); // Return the minimum of both ranges
}

void solve(int tc)
{

    int n, q;
    cin >> n >> q;
    int typ;
    int l, r;
    int v;
    build(1, 1, mx - 1);
    while (q--)
    {
        cin >> typ;
        if (typ == 1)
        {
            cin >> l >> r >> v;
            v *= -1LL;
            update(1, 1, mx - 1, l, r, v);
        }

        else
        {
            cin >> l >> r;
            // cout<<"111";

            cout << query(1, 1, mx - 1, l, r) << endl;
        }
    }
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    // cin >> t;
    //  in(t);
    //  cin.ignore();

    //   start();
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}
