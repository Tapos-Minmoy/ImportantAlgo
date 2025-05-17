#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int mxN = 17;
const int mx = 1e5 + 2;
int LCA[mx][mxN + 1];
int level[mx];
vector<int> adj[mx];
void dfs(int node, int lvl, int par)
{
     // tree flattening tachnic
     // vis array will not require as the graph is tree
     level[node] = lvl;
     LCA[node][0] = par;
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
               }
          }
     }
}

int getLCA(int a, int b)
{
     if (level[b] < level[a])
          swap(a, b);
     int d = level[b] - level[a];
     while (d > 0)
     {
          // jump d
          int jump = log2(d);
          b = LCA[b][jump];
          d -= (1 << jump);

          // merge(odd.begin(), odd.end(),even.begin(), even.end(),inserter(s, s.begin()));
     }
     // 10^5*10*20*2
     if (a == b)
          return a;

     for (int i = mxN; i >= 0; i--)
     {
          // jump till find equal with maximum capacity
          if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
          {
               a = LCA[a][i];
               b = LCA[b][i];
          }
     }

     return LCA[a][0];
}

int query(int a, int b)
{
     return getLCA(a, b);
}

int main()
{
}
