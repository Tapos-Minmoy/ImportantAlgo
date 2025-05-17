#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6;
int mnN[mx][20];
int mxN[mx][20];
void sparse(int *R, int n)
{
     for (int i = 0; i < n; i++)
     {
          mxN[i][0] = R[i];
          mnN[i][0] = R[i];
     }

     for (int j = 1; (1 << j) <= n; j++)
     {

          for (int i = 0; (i + (1 << j) - 1) < n; i++)
          {

               mxN[i][j] = max(mxN[i][j - 1], mxN[i + (1 << (j - 1))][j - 1]);
               mnN[i][j] = min(mnN[i][j - 1], mnN[i + (1 << (j - 1))][j - 1]);
          }
     }
}
int Querymn(int L, int R)
{

     int j = (int)log2(R - L + 1);
     // pair<int,int>cur;
     // cur.first=max(mxN[L][j],mxN[R-(1<<j)+1][j]);
     return min(mnN[L][j], mnN[R - (1 << j) + 1][j]);
}
int Querymx(int L, int R)
{
     int j = (int)log2(R - L + 1);
     // pair<int,int>cur;
     // cur.first=max(mxN[L][j],mxN[R-(1<<j)+1][j]);
     return max(mxN[L][j], mxN[R - (1 << j) + 1][j]);
}

int main()
{

     // warning zero based indexing

     int n;
     cin >> n;

     int a[n + 1];

     int last[n + 1];

     memset(last, -1, sizeof(last));
     map<int, int> mp;

     set<pair<int, int>> st;

     for (int i = 0; i < n; i++)
     {
          cin >> a[i];
          mp[a[i]]++;
          last[a[i]] = i;
     }

     for (int i = 1; i <= n; i++)
     {
          if (last[i] != -1)
               st.insert({last[i], i});
     }

     sparse(a, n);
     int len = mp.size();

     for (int i = 1; i <= len; i++)
     {

          auto kk=st.begin();
          int id=kk->f;

          if(i&1)
          {

               

          }
          else
          {

          }
     }

     return 0;
}
