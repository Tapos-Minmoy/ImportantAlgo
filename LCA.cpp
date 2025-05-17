#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int mxN = 17;
const int mx = 1e5 + 2;
int LCA[mx][mxN + 1];
vector<int> st[mx][mxN + 1];
vector<int> C[mx];
int level[mx];
vector<int> adj[mx];
void merge_set(vector<int> &ans1, vector<int> &ans2)
{
     int cnt = 0;
     vector<int> res(22);
     merge(ans1.begin(), ans1.end(), ans2.begin(), ans2.end(), res.begin());

     res.resize(unique(res.begin(), res.end()) - res.begin());
     int sz = res.size() - 1;
     if (res[sz] == 0)
          res.pop_back();
     if (res.size() > 10)
          res.resize(10);
     ans1 = res;
}

void dfs(int node, int lvl, int par)
{
     // tree flatennign is here
     level[node] = lvl;
     LCA[node][0] = par;
     merge_set(st[node][0], C[node]);
     if (par != -1)
     {
          merge_set(st[node][0], C[par]);
     }

     for (auto x : adj[node])
     {
          if (x != par)
          {
               dfs(x, lvl + 1, node);
          }
     }
}
void build(int n)
{
     dfs(1, 0, -1);

     for (int i = 1; i <= mxN; i++)
     {
          for (int j = 1; j <= n; j++)
          {
               if (LCA[j][i - 1] != -1)
               {
                    int par = LCA[j][i - 1];
                    LCA[j][i] = LCA[par][i - 1];
                    // merge set of  st[j][i-1] and st[par][i-1] with at mx lenth 10
                    // But I am not sure casue this could give RTE,IDk,
                    merge_set(st[j][i], st[j][i - 1]);
                    merge_set(st[j][i], st[par][i - 1]);
               }
          }
     }
}

vector<int> get_ans(int a, int b)
{
     if (level[b] < level[a])
          swap(a, b);
     int d = level[b] - level[a];
     vector<int> result;
     merge_set(result, C[a]);
     merge_set(result, C[b]);
     while (d > 0)
     {
          // jump d
          int jump = log2(d);
          merge_set(result, st[b][jump]);
          b = LCA[b][jump];
          d -= (1 << jump);

          // merge(odd.begin(), odd.end(),even.begin(), even.end(),inserter(s, s.begin()));
     }
     if (a == b)
          return result;

     for (int i = mxN; i >= 0; i--)
     {
          // jump till find equal with maximum capacity
          if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
          {
               merge_set(result, st[a][i]);
               merge_set(result, st[b][i]);
               a = LCA[a][i];
               b = LCA[b][i];
          }
     }

     merge_set(result, st[a][0]);
     merge_set(result, st[b][0]);
     return result;
}
void query(int a, int b, int c)
{
     vector<int> cur = get_ans(a, b);
     int sz = cur.size();
     cout << min(sz, c) << " ";
     for (auto x : cur)
     {
          if (c > 0)
               cout << x << " ";
          c--;
     }
     cout << endl;
}

int main()
{

     int n, m, a, b, q;
     cin >> n >> m >> q;

     for (int i = 1; i <= n; i++)
     {
          for (int j = 0; j < mxN; j++)
          {
               LCA[i][j] = -1;
          }
     }

     for (int i = 1; i < n; i++)
     {
          cin >> a >> b;
          adj[a].pb(b);
          adj[b].pb(a);
     }

     for (int i = 1; i <= m; i++)
     {
          cin >> a;
          C[a].pb(i);
     }
     for (int i = 1; i <= n; i++)
     {
          if (C[i].size() > 10)
               C[i].resize(10);
     }
     build(n);
     // How much garbage that even computing space and time complexity become a difficult task
     // I have just replace set by vector ,,see what happend

     /* for(int i=1;i<=n;i++)
      {
           for(int j=0;j<=3;j++)
           {
                cout<<i<<" "<<j<<endl;
                for(auto x:st[i][j])cout<<x<<" ";
                cout<<endl;
           }
      }*/
     int c;
     while (q--)
     {
          cin >> a >> b >> c;
          query(a, b, c);
     }

     return 0;
}
