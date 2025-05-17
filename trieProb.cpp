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

typedef struct Tree
{
    struct Tree *bit[2];

    vector<int> v;

} NewTree;

NewTree *getNode()
{
    NewTree *Newnode = new NewTree;
    for (int i = 0; i < 2; i++)
    {
        Newnode->bit[i] = NULL;
    }

    return Newnode;
}
void Insert(int x, int id, NewTree *root)
{

    bitset<32> X(x);

    for (int i = 31; i >= 0; i--)
    {
        if (root->bit[X[i]] == NULL)
            root->bit[X[i]] = getNode();

        root->bit[X[i]]->v.pb(id);
        root = root->bit[X[i]];
    }
}

void Search(int x, NewTree *root)
{
    bitset<32> X(x);

    string st;
    for (int i = 31; i >= 0; i--)
    {
        if (root->bit[X[i]] == NULL)
            root->bit[X[i]] = getNode();
        st.pb(X[i] + '0');
        cout << st << endl;

        for (int x : root->bit[X[i]]->v)
        {
            cout << x << " ";
        }

        cout << endl;

        root = root->bit[X[i]];
    }
}
void Del(int x, NewTree *root)
{
    bitset<32> X(x);

    string st;
    for (int i = 31; i >= 0; i--)
    {
        if (root->bit[X[i]] == NULL)
            root->bit[X[i]] = getNode();
        st.pb(X[i] + '0');

        root->bit[X[i]]->v.pop_back();
        for (int x : root->bit[X[i]]->v)
        {
            //  cout << x << " ";
        }

        //  cout << endl;

        root = root->bit[X[i]];
    }
}

int find(string &s, NewTree *root)
{

    int p = 0;
    int sz = s.size();
    for (int i = 31; i >= 0 && p < sz; i--, p++)
    {
        if (root->bit[s[p] - '0'] == NULL)
            return -1;
        if (root->bit[s[p] - '0']->v.empty())
            return -1;
        if (p == sz - 1)
        {
            return root->bit[s[p] - '0']->v.back();
        }

        root = root->bit[s[p] - '0'];
    }

    return -1;
}
void solve(int tc)
{

    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    NewTree *root = getNode();

    for (int i = n; i >= 1; i--)
    {
        Insert(a[i], i, root);
    }

    int paichi = INT_MAX;
    for (int i = 1; i <= n; i++)
    {

        bitset<32> X(a[i]);
        string s;
        for (int j = 31; j >= 0; j--)
        {
            if (bit(k, j))
            {
                bool kk = 1 - X[j];
                s.pb(kk + '0');
            }
            else
            {
                // k is unset
                // 1
                bool kk = 1 - X[j];
                s.pb(kk + '0');
                int ans = find(s, root);
                if (ans != -1)
                {
                    paichi = min(paichi, ans - i + 1);
                }
                s.pop_back();
                s.pb(X[j] + '0');
            }
        }

        int kk = find(s, root);
        if (kk != -1)
            paichi = min(paichi, find(s, root) - i + 1);

        // Search(a[i], root);
        // break;
        Del(a[i], root);
    }

    if (paichi == INT_MAX)
        paichi = -1;

    cout << paichi << endl;
    //   cout << "YES" << endl;

    // 0001
    // 0010
    // 0011
    // 0100
    // 0101
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
