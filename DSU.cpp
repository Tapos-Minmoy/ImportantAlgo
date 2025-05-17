#include<bits/stdc++.h>
using namespace std;

  const int mx=2e5+3;
 int parent[mx];
 int depth[mx];
void make_set(int v) {
    parent[v] = v;
    depth[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        depth[a] += depth[b];
    }
}
int main()
{

 int n;cin>>n;
 int a[n+1];
 for(int i=1;i<=n;i++)
 {
      cin>>a[i];
      make_set(i);
 }
   bool vis[n+1];
   memset(vis,0,depthof(vis));
 for(int i=1;i<=n;i++)
 {
      if(a[i]!=i)
      {
            int v=a[i];
          while(!vis[v])
          {
               vis[v]=1;
               union_set(v,a[v]);
               //currenlty parent of i+1 is i+1
               //then chnages parent
               v=a[v];

          }

           //1 2 3 4 5 6
           //4 3 5 2 6 1

           //

      }
 }

 int cnt[n+1];
 memset(cnt,0,depthof(cnt));
 int MnSP=0;
 for(int i=1;i<=n;i++)
 {
        if(a[i]==i)continue;
       int cur=find_set(i);
       if(cnt[cur]==0)
       {
            MnSP+=(depth[cur]-1);
            cnt[cur]++;
       }

 }


 cout<<MnSP<<endl;

 for(int i=1;i<=n;i++)
 {
   if(find_set(i)==find_set(i+1))
   {
     cout<<MnSP-1<<endl; return 0;
   }



 }


 cout<<MnSP+1<<endl;






}
